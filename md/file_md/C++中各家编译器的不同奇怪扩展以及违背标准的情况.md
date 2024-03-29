- [前言](#前言)
  - [`C99`的变长数组(`VLA`)](#c99的变长数组vla)
    - [总结](#总结)
  - [非常量左值引用能接纯右值？](#非常量左值引用能接纯右值)
    - [总结](#总结-1)
  - [内建下标访问运算符中`msvc`违背C++标准？](#内建下标访问运算符中msvc违背c标准)
    - [总结](#总结-2)
  - [你真的懂弃置函数？`函数名()=delete`](#你真的懂弃置函数函数名delete)
    - [前置知识](#前置知识)
    - [步入正题](#步入正题)
    - [总结](#总结-3)
  - [`lambda`表达式隐式捕获，到底谁违反了`C++`标准？](#lambda表达式隐式捕获到底谁违反了c标准)
    - [总结](#总结-4)
  - [零长数组？](#零长数组)
    - [柔性数组问题](#柔性数组问题)
    - [函数声明0长数组？](#函数声明0长数组)
    - [总结](#总结-5)
  - [`{}`初始化，到底谁错了？](#初始化到底谁错了)
    - [总结](#总结-6)
  - [`msvc`的`std::exception`](#msvc的stdexception)
    - [总结](#总结-7)
  - [`msvc`又赢了？默认实参问题](#msvc又赢了默认实参问题)
    - [总结](#总结-8)
  - [`#define`的问题](#define的问题)
  - [重载决议](#重载决议)
    - [总结](#总结-9)
  - [`msvc`查找标识符的奇怪问题](#msvc查找标识符的奇怪问题)
  - [`msvc`有趣的返回值使用匿名结构体扩展](#msvc有趣的返回值使用匿名结构体扩展)
  - [转换构造函数复制初始化的问题](#转换构造函数复制初始化的问题)
- [总结](#总结-10)


# 前言

**本文的主题很简单，就是介绍那些平时使用的时候，很容易依赖当前编译器的东西而非标准`C++`导致的各种不兼容的问题。**

这可能是因为编译器不遵守标准规定，也可能是因为编译器扩展。**注意:我们不会介绍各个编译器所有的编译器扩展，只是在一些的确容易间接依赖到的地方，才会强调。**

当然，也欢迎各位补充！

## `C99`的[变长数组(`VLA`)](https://zh.cppreference.com/w/c/language/array)

默认情况下在我们写`C++`的时候`gcc` `clang`是支持了`C`语言的这一特性，这有什么大问题吗？

不大不小。听我们往下说：下面这段[**代码**](https://godbolt.org/z/7jWh6dn1a)使用`gcc13.1`和`clang16.0`都不存在任何问题。但是当你想移植在`msvc`上，就会给你一个编译错误，这是理所应当的，因为这的确违背了标准`C++`的规定。

```cpp
#include <iostream>

int main(){
    int n=10;
    int arr[n];
    std::cout<<sizeof arr<<'\n';
}
```

标准C++要求声明[数组](https://zh.cppreference.com/w/cpp/language/array)时`[ 表达式 ]`:求值为大于零的值的整型常量表达式 (C++14 前) `std::size_t` 类型的经转换常量表达式 (C++14 起)

这点移植性问题其实如果你真的清楚这个扩展，也不算大事。**更大的问题是，这会让很多人产生一些理解性的错误**

```cpp

#include <iostream>

template<int n>
struct X{
    int v = n;
};

int main(){
    int n=10;
    const int n2 = 10;

    int arr[n];//VLA
    int arr2[n2];//普通数组
    //↓ok
    X<n2>x1;
    std::cout<<x1.v<<'\n';
    X<sizeof arr2>x2;
    std::cout<<x2.v<<'\n';
    //↓on
    X<n>x3;
    X<sizeof arr>x4;
}
```

看上面这段代码，差不多算是别人提问的:**"为什么这个模板的参数得用const的？还有，sizeof为啥一个可以一个不可以？"**

显然，这里和什么是是不是`const`毫无关系，单纯的，是不是常量表达式罢了。`const int n2 = 10;`是一个典型的常量表达式，这应当参见[**`模板非类型实参`**](https://zh.cppreference.com/w/cpp/language/template_parameters)的要求

即:对于整型和算术类型，实例化时所提供的模板实参必须是模板形参类型的[经转换常量表达式](https://zh.cppreference.com/w/cpp/language/constant_expression)（因此适用某些隐式转换）。

至于`sizeof`运算符的问题，实际上按照`C++`标准规定，它肯定是常量表达式，但是呢，因为`VLA`，这一不属于`C++`的东西，那么自然这里的情况就得参见[`C`的文档](https://zh.cppreference.com/w/c/language/sizeof)了:

    若 表达式的类型为非常量长度数组类型，则求值 表达式 ，并在运行时计算其所求值的数组大小。(C99 起)

那么运行时，自然不算常量表达式。

其实还不止如此，`C99`的`VLA`拥有着众多的语法，我们不一一介绍，我们再提一点和别的编译器不同的问题，看如下代码:

```cpp
void foo(size_t x, int a[*]);
void foo(size_t x, int a[x])
{
    printf("%zu\n", sizeof(a)); 
}
int main(){
    size_t n=10;
    int array[n];
    foo(n,array);
}
```

运行结果:

    8

这段代码，`gcc`无法运行，`clang`可以，其实这两个编译器默认都有`VLA`的扩展，但是呢，`gcc`其实只是支持了一部分，没有完全支持，像上面那个也是`C99`的写法，`gcc`就是不支持。所以，对无规定的扩展，不要有侥幸心理，认为别的编译器可能给你好好的支持。


### 总结

好了，相信这第两个简单的问题，已经能让你意识到了一些问题，其实如果使用者真的清楚，那么利用这些兼容的扩展，清楚自己在做什么，也无伤大雅。但是更多的是大多数人不清楚自己在写什么，编译器过了就过了，包括过度依赖编译器，很多思考理解问题的方式，都有很大的问题。

---

## 非常量左值引用能接纯右值？

这是一个很奇怪的扩展，来自于`msvc`，在将标准设置为`C++20`之前即可，我相信，一定也有人，有代码，依赖了此扩展，代码如下:

```cpp
#include <iostream>

struct X{};
X f() { return {}; }

int main() {
    X& x = f();
}
```

`msvc`编译器不但通过了编译，甚至一个警告都没有，`visual studio 2022`倒是有提示，但是这是`lntelliSense`，这是两套东西。
看着是不是很奇怪？ **"怎么会有人写出这样的代码？"** 

这至少因为这个`demo`十分的简单明了，自然可以一眼发现，但是在复杂的情况下，可能多数时候，开发者们没办法关注到这些。

更有趣的是，我们可以观测一下`X`对象的生存期，是何时析构的

```cpp
#include <iostream>

struct X {
    ~X() { puts("~X()"); }
};
X f() { return {}; }

int main() {
    X& x = f();
    puts("~~~");
}
```

运行结果:

`~~~`

`~X()`


你知道这代表了什么吗？或许，我们可以理解为`msvc`的扩展让它普通引用的效果，能像`const T&`和`T&&`那样，延长临时对象的[生存期](https://zh.cppreference.com/w/cpp/language/lifetime)

再说直接一点就是，**这个错误不容易被发现**，因为在`msvc`下，它运行的完全和正常写法用`const T&`和`T&&`没区别

当你要将代码移植到其他编译器，尤其是代码量非常巨大的项目，这一个问题，我觉得你应该是难以找到。

### 总结
事情是不是更加有趣了起来？还有很多呢，远不止如此

---

## 内建下标访问运算符中`msvc`违背C++标准？

如标题所说(`msvc`不遵守`C++`标准，与众不同，其实由来已久，倒也没啥奇怪的)，我们需要介绍一下[内建的下标访问运算符](https://zh.cppreference.com/w/cpp/language/operator_member_access)。

其实问题很简单，就是一句话

    内建下标表达式E1[E2]应用到数组时，如果数组是左值，那么 (C++11 起)下标表达式是左值，否则是亡值 (C++11 起)。

看着很简单对吧？我们只需要写一个`demo`测试一下就好了

```cpp
#include <iostream>
#include<type_traits>

int main() {
	using T = int[3];
	using Type = decltype(T{} [0]) ;
	std::cout << std::boolalpha << std::is_rvalue_reference_v<Type> << '\n';
}
```

根据[`decltype(表达式)`](https://zh.cppreference.com/w/cpp/language/decltype) 如果表达式的值类别是**亡值**，将会decltype产生`T&&`；我们写下了
```
using Type = decltype(T{} [0]) ;
std::is_rvalue_reference_v<Type>
```
这段代码在`msvc`下是 **`false`**，在`gcc`和`clang`都是 **`true`**

显然是`msvc`违背了规定。

### 总结

至于这又会产生一些什么`bug`或移植问题，我相信看了前面两个问题，你应该会有一些想法了，不过嘛，**数组右值使用毕竟还是比较少，可能也不算很常见**。

---

## 你真的懂[弃置函数](https://zh.cppreference.com/w/cpp/language/function)？`函数名()=delete`

以我的视角，我说一个主观的的我个人认为的大概的数据，**`95%`** 的人并不懂这个东西，只是会一些基本的禁止一些特殊的成员函数，仅此而已。

### 前置知识

我们要讲这弃置函数不同编译器的一些问题，但是在此之前，我们更应该普及点基本的`C++`规定，避免错误的理解。

首先我们要明白一个最基本的问题

```cpp
void f()=delete;
```

这是一个什么？"弃置函数" 。对，的确是。那么我们说直接一点，这是一个**函数定义**，也就是和`void f() {}`没什么不同。他们都是`函数定义`，他们的`函数体`不同，是`{}`复合语句，以及`=delete`，都是函数体。

你可能不明白我为什么要强调这些？不要着急，我们看下面代码:

```cpp
void f(int){}
void f(double)=delete;
```

这倒也不算冷门写法，很多书籍（如《`Effective Modern C++`》）基本都会提到这种作用，他们可能常用"禁止隐式转换"，“删除xx类型的函数”这种说辞，但其实这十分不准确，那么让我来说吧。

    上面的两个都是函数定义，那么他们实际上构成了一个函数重载，不是吗？
    那么既然如此，我们看下面调用

```cpp
f(1);//ok
f(1.2)//error
```

这无非是因为`1.2`是`double`类型，弃置函数比`void f(int)`更加匹配，被**重载决议**选择了罢了，它选择到了
`void f(double)=delete;`。

那么根据规定

    如果弃置函数被重载，那么首先进行重载决议，且只有在选择了弃置函数时程序才非良构。

那么到此，如果你全部看完了，我相信你应该可以理解弃置函数了，那么接下来，我们就可以开始**进入正题**了！

### 步入正题

```cpp
#include <iostream>

struct X {
	X() = default;
	X(const X&) = default;
	X(X&&) = delete;
};
X f() {
	X x;
	return x;
}

int main() {
	X x = f();
}
```

给出以上代码，你觉得是否能通过编译？相信看了上面的，你也该猜到了，这就是本节的重点，必定是有编译器不同或违背标准的情况。

那么我们先合理分析一下，`X`类有默认构造，复制构造，但是**移动构造被删除了**，函数`f()`里面是`return x`

我们知道，`return`会选择移动构造和复制构造，通常重载决议会选择移动构造，但是当移动构造不存在的时候，也是会选择复制构造的。

**显然，上面这段代码是编译错误，问题就出在移动构造被显式弃置了**。

我知道你会有疑问：”不是说没有移动构造的话，也是可以选择复制构造吗？“

    对，的确，但是真的没有吗？

    记得我们之前说了什么吗？ 弃置函数不就是函数定义吗，这不是有吗？

    并且弃置函数可以参与重载决议，移动构造比复制构造更合适，被选择，但是因为是弃置的，那么非良构，编译错误。

“如果直接把`X(X&&) = delete;`这一行去掉呢？”

    那的确没问题，还记得 0 3 5 法则这些吗，显式的复制构造不就是会阻止移动构造的隐式定义了吗？（大家也可能喜欢用“隐式删除”这个词语，也没毛病，和弃置函数的“显式删除”的用词对应）

    也就是编译器不会为你生成移动构造，没有移动构造，自然可以选择复制构造，也不存在重载决议的问题，因为压根没有，不是吗？

那么好，这是合理的解释和分析，是完全正确的，我们接下来该说说编译器的一些问题了，即 **`gcc`** 的 **`BUG`**。

经过测试，自`gcc8.1`起到`gcc12.2`，`C++17`的环境下，这个`BUG`就存在了，**上面段代码可以通过编译**。

在最新的`gcc13`下，这个bug被修复了，我不知道有多少人间接依赖了这个bug。

然后更新编译器的时候这里报错那里报错，就在网上说 **“新版本不稳定，不兼容xxxx”，实际上自己写的代码都沾点大病**。

### 总结

这个问题稍微有点绕，需要不少的前置的认知，主要还是因为多数人的认知是错误的，或者不全面的，所以无法理解这个问题，我们就只能在开头重新介绍了。

---

## [`lambda`表达式](https://zh.cppreference.com/w/cpp/language/lambda)隐式捕获，到底谁违反了`C++`标准？

```cpp
#include <iostream>

int main() {
	const int N = 10;
	auto p = [] {
		int n = N;
	};
	std::cout << sizeof p << '\n';
}
```

给出上面的代码，你觉得是否正确？

显然，根据标准规定:

    如果变量满足下列条件，那么 lambda 表达式在读取它的值前不需要先捕获：
        该变量具有 const 而非 volatile 的整型或枚举类型，并已经用常量表达式初始化，或者
        该变量是 constexpr 的且没有 mutable 成员。

那么，这段代码应该没有任何问题，对吗？毕竟`const int N = 10;`的确符合上面说的

然而，与众不同的`msvc`，在这里是没有遵守规定，或者说这是个`BUG`，可能是故意的，也可能是不小心的。

这段代码在`visual studio 2022`的`C++20`之前无法通过编译，需要显式的捕获，但是其实也不是所有语境都不行，我们看下面的情况，`msvc`就在`20`之前也允许

```cpp
int main() {
	const int N = 10;
	auto p =[] {
		int arr[N]{};
	};
}
```

至于为什么？谁知道呢，在`visual studio 2022`开启`C++20`和`C++23`的情况下，这个bug已经不存在了。

### 总结

这个倒是编译器的`BUG`问题了，不是开发者的锅，移植就是这么麻烦，建议是能用多新就用多新的，那些满嘴**老版本稳定**的人都不知道依赖了多少编译器`BUG`，扩展啥的，让它更新个标准，要了命了。

---

## 零长数组？

### 柔性数组问题

这实际上是一个经典问题了，理论上不该有这种东西的存在，我们需要强调的其实还是`C99`柔性数组，虽然按道理`C++`没有这玩意，但是大部分编译器都对此有扩展，即:

```cPP
#include<iostream>
#include<string.h>

struct test
{
	int a;
	double b;
	char c[0];
};
int main() {
	auto t = (test*)malloc(sizeof(test) + 27 * sizeof(char));
	memset(t->c, 0, 27);//记得置0
	std::cout << sizeof * t << std::endl;
	for (int i = 0; i < 26; i++) {
		t->c[i] = 'A' + i;
	}
	std::cout << t->c << std::endl;
	free(t);
}
```

运行结果:

    16
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

在`gcc` `clang` `msvc` 全部可以通过编译（[`msvc`会给出警告](https://learn.microsoft.com/zh-cn/cpp/error-messages/compiler-warnings/compiler-warning-levels-2-and-4-c4200?view=msvc-170)），但是，这不但不符合标准`C++`，甚至不符合标准`C`，标准`C99`对`struct`中柔性数组的要求是:

    若结构体定义了至少一个具名成员，则额外声明其最后成员拥有不完整的数组类型。访问柔性数组成员的元素时（在以柔性数组成员名为 . 或 -> 的右侧运算数的表达式中），结构体表现得如同该数组成员拥有为此对象分配的内存中最长的适合大小。若未分配额外存储，则它表现为如同有 1 个元素的数组，除了若访问该元素，或产生指向该元素后一位置指针，则行为未定义。初始化、 sizeof 及赋值运算符忽略柔性数组成员。拥有柔性数组成员的结构体（或拥有可能递归的有柔性数组成员的结构体成员的联合体）不能作为数组元素，或其他结构体的成员出现。

实际上说的是`不完整的数组类型`，你怎么可以用所谓**0长数组**？显然这是不符合要求的。

只是呢，的确，**虽然没有任何必要去使用它**，但是起码简单的测试中，这些编译器默认都开启了这些扩展，且允许了。

如果你在这个地方遇到了坑可以提出来。

### 函数声明0长数组？

```cpp
#include<iostream>
#include<string.h>

void f(int arr[0]){std::cout<<*arr<<'\n';}

int main(){
    int*p=new int{1};
    f(p);
}
```

运行结果:

    1

`gcc` `clang`可以通过编译，`msvc`不行。

那么好，我们又要稍微的分析一下到底这是谁的锅了，首先，我们参见标准规定的函数声明里:

    形参列表中的每个函数形参的类型根据下列规则确定:
    如果类型是“T 的数组”或“T 的未知边界数组”，那么它会被替换成类型“指向 T 的指针”。

这么看，那里面的**0长数组**只是长着像，实际上是指针，那么按照`C++`的规定，这是否是被允许的呢？

    显然不太可能，`C++`是不允许0长数组的（`new T[0]` 除外）。
    即使是C语言，也是一样的
    C语言不允许零长度数组，即使一些编译器作为扩展提供它们（典型例子是 C99 前的柔性数组成员实现）。

`gcc` `clang`甚至允许直接声明0长数组，比如`int arr[0];`。这些都是非标准行为，在`msvc`不被允许

不过不管怎么样，虽然我想不到什么人，会以一种什么心态写下这种代码，但是，我希望，你们不要这么写，哪怕可以用。

### 总结

这一局可以说`msvc`完胜。

我们扯到了不少东西，我们稍微区分一下：

1. 编译器在`C++`的情况下扩展了对`C`的一些支持（本节是`C99`柔性数组）。

2. 扩展了一些不是`C`的，完全是凭空产生的写法，不建议使用，即所谓的**0长数组**

上面说的其实我全部都不建议使用，除非是对你非常需要，知道自己在做什么事情。

我说了这么多只是为了让你懂自己在写什么，不要天天稀里糊涂的去写。

---

## `{}`初始化，到底谁错了？

```cpp
struct S {
    int a;
};
using s2 = S[2];

int main() {
    s2{ 1,2 };
    s2 s2{ 1,2 };
}
```

上面这段代码，`s2 s2{ 1,2 };`是一个对照组，它在所有编译器下都是正确的，主要是看上面的构造无名对象的写法是否正确。

那么这段代码，在`gcc`和`clang`是可以通过编译的，但是在`msvc`，是编译错误。

我们需要修改一些写法才可以让它在`msvc`也通过编译，如下:

```cpp
struct S {
    int a;
};
using s2 = S[2];

int main() {
    s2{ {1},{2} };
    s2 s2{ 1,2 };
}
```

```cpp
struct S {
    int a;
    S(int v):a{v}{}//!!!!
};
using s2 = S[2];

int main() {
    s2{ 1,2 };
    s2 s2{ 1,2 };
}
```

这两种更改都可以，即增加转换构造函数，或嵌套`{}`。

那么原因呢？为什么？其实我想了很多，我也没想到，你可以认为，我也不算十分清楚，这个问题就留给你们了。

### 总结

编译器往往就是有这些奇奇怪怪的事情，习惯即可，即使不能完全明白原因，知道也不是坏事。

---

## `msvc`的`std::exception`

```cpp
#include<iostream>
#include<exception>

struct MyException :std::exception {
	MyException(const char* message) :exception(message) {}
};

void f()try{
	throw MyException("乐");
}catch (const std::exception&e){
	std::cerr << e.what() << '\n';
}

int main() {
	f();
}
```

以上代码是否正确？

    实际上在msvc下是正确的，当然，标准C++的规定里，std::exception类压根没有const char*的构造函数。
    如果是gcc，clang，那自然无法通过编译。
    
`std::exception`的构造函数参阅[文档](https://zh.cppreference.com/w/cpp/error/exception/exception)


`msvc`实现了这个构造函数:

```cpp
explicit exception(char const* const _Message) noexcept
    : _Data()
{
    __std_exception_data _InitData = { _Message, true };
    __std_exception_copy(&_InitData, &_Data);
}
```

正常的写法自然应该是重写虚函数`what()`，如下:

```cpp
#include <iostream>
#include<exception>

struct MyException :std::exception {
	const char* data{};
	MyException(const char* s) :data(s) { puts("MyException()"); }
	~MyException() { puts("~MyException()"); }
	char const* what()const{ return data; }
};

void f()try {
	throw MyException("乐");
}
catch (const std::exception& e) {
	std::cerr << e.what() << '\n';
}
int main() {
	f();
}
```

以上代码是否正确？

    实际上还是msvc专属的，因为what()方法

按照标准规定，`what()`应该声明为下面这样：
```cpp
virtual const char* what() const noexcept;
```

但是呢，在`msvc`的实现是：

```cpp
_NODISCARD virtual char const* what() const
{
    return _Data._What ? _Data._What : "Unknown exception";
}
```

`msvc`的可没有`noexcept`修饰，自然可以按照上面的写法了（笑）。

那么正确的写法应该是下面这样:

```cpp
#include <iostream>
#include<exception>

struct MyException :std::exception {
	const char* data{};
	MyException(const char* s) :data(s) { puts("MyException()"); }
	~MyException() { puts("~MyException()"); }
	char const* what()const noexcept{ return data; }
};

void f()try {
	throw MyException("乐");
}
catch (const std::exception& e) {
	std::cerr << e.what() << '\n';
}
int main() {
	f();
}
```

那么我相信你还会有疑问：“`msvc`的是非`noexcept`的，你重写的是有`noexcept`的，在`C++17`，这不是构成重载了吗？明明两个函数不一样”。

    重写实际上只是要求了不能损失不抛出保证，即原本是noexcept要加noexcept。原本不是的你不加也行。

### 总结

是不是好像又觉得`msvc`怎么总喜欢在这些无关紧要的地方搞特殊？也不是核心语言特性，就是一些规定好的库实现都搞特殊。

很容易让开发者依赖到，毕竟不会人人写代码都防着编译器，先看看文档，能跑大概率就当没问题，有这个构造函数了。

没有什么好办法，这些事情我们得自己注意到，迟早会栽跟头。

---

## `msvc`又赢了？默认实参问题

```cpp
struct X {
	int n = 6;
	static const int a = 6;
	void f(int n = sizeof + n) { std::cout << n << '\n'; }
	void f_(int n = a) { std::cout << n << '\n'; }
};

int main(){
	X().f();//error
	X().f_();//ok
}
```

以上代码是否正确？

在`clang` `gcc`下，正确，运行结果：

    4
    6

`msvc` 编译错误，编译器给出的信息如下：

[error C2648: “X::n”](https://learn.microsoft.com/zh-cn/cpp/error-messages/compiler-errors-2/compiler-error-c2648?view=msvc-170): 将成员作为默认参数使用要求静态成员

[error C2355: “this”](https://learn.microsoft.com/zh-cn/cpp/error-messages/compiler-errors-1/compiler-error-c2355?view=msvc-170): 只能在非静态成员函数或非静态数据成员初始值设定项的内部引用

其实我觉得已经说的非常清楚了，尤其是你点进`msdn`看微软给的`demo`，但我们还是强调一下`C++`的基本规定：

    默认实参中不能使用非静态的类成员（即使它们不被求值），除非用于构成成员指针或在成员访问表达式中使用。

`f_()`只是一个对照组，不用太过在意。

**所以说`msvc`是正确的**，即使是在最新的`gcc13.1`和`clang16`，这个问题依旧没有被修复，`msvc`这局可以说赢了！

### 总结

`msvc`又扳回一局了，那么接下来是否还可以呢？实际上默认实参那个操作倒也不算非常常见，我们将介绍一些更加常见，更可能使用到的一些编译器不同点。

---

## `#define`的问题

`define`在`C/C++`当中十分常见，你几乎可以在任何场景看到它的使用，起本身语法其实也算是挺多的，但是即使是标准规定的语法，某些编译器也没有，比如 **`msvc`**。

`C++20`起，增加了一个`__VA_OPT__`这样的语法：

```cpp
#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)
#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)
#define SDEF(sname, ...) S sname __VA_OPT__(= { __VA_ARGS__ })
F(a, b, c) // 替换为 f(0, a, b, c)
F()        // 替换为 f(0)
G(a, b, c) // 替换为 f(0, a, b, c)
G(a, )     // 替换为 f(0, a)
G(a)       // 替换为 f(0, a)
SDEF(foo);       // 替换为 S foo;
SDEF(bar, 1, 2); // 替换为 S bar = { 1, 2 };
```

是不是好像觉得也没啥意思了？毕竟不是什么很特殊的随便经常会用到的东西，我也在思考，`msvc`在预处理器这里给的扩展是很多的，到底要不要都提一下？

没啥必要，看需求使用就是。

---

## 重载决议

```cpp
#include<iostream>
void f(const int(&)[]) { puts("const int(&)[]"); }
void f(const int(&)[2]) { puts("const int(&)[2]"); }
void f(int(&&)[]) { puts("const int(&&)[]"); }

int main() {
    f({ 1,2,3 });
    f({ 1,2 });
}
```

运行结果:

    const int(&&)[]
    const int(&&)[]

`msvc`和`clang`编译正确，`gcc13`编译错误，很少见，真的很少见。

怎么说呢？一般来说，都是`gcc`和`clang`会是一样的，很少会有不同（至少在本文，这是第二次，上一次就是`gcc`的`BUG`）。

这显然也是一个`gcc`的`BUG`，按照重载决议，这里显然是右值引用优于左值引用的，这是个右值表达式。

`gcc`对这个`{}`的重载决议的匹配是有大问题的，上面是非常简单的`demo`，但是稍微想想也该知道，这应该证明很多情况都有问题，比如下面的这种：

```cpp
#include<iostream>
struct X { int x, y; };

struct Y {
    Y(std::initializer_list<int>){}
};

void f(const int(&)[]) { puts("const int(&)[]"); }
void f(const int(&)[2]) { puts("const int(&)[2]"); }
void f(int(&&)[]) { puts("int(&&)[]"); }
void f(X) { puts("X"); }
void f(Y) { puts("Y"); }


int main() {
    f({ 1,2,3 });
    f({ 1,2 });
    f({ .x=1,.y=2 });
}
```

运行结果:

    int(&&)[]
    const int(&)[2]
    X

依然是`gcc`**无法通过编译**。


### 总结 

`gcc`是卢瑟。

---

## `msvc`查找标识符的奇怪问题

```cpp
template<size_t n>
struct X {
	static const int n = X<n-1>::n+n;
};
template<>
struct X<0> {
	static const int n = 0;
};
```

给出如上代码，你觉得是否可以正常通过编译呢？

    我相信，如果你细心的话就已经发现了，这个非类型模板形参的名字，似乎和静态数据成员重名了。

**都是`n`** 那么这是否有问题呢？的确，这就是本节内容的重点。

此代码在`gcc`不可被编译，无法通过语法检查，但是在`msvc`，毫无问题，先说结论，这应该可以算作是一个`msvc`的扩展的问题。（如你有其他更清楚的看法也可以提出来）。

**`gcc11`**编译器给出的提示如下:

    main.cpp:1:10: error: 'size_t' has not been declared
    1 | template<size_t n>
      |          ^~~~~~
    main.cpp:3:28: error: 'n' was not declared in this scope
    3 |     static const int n = X<n-1>::n+n;
      |                            ^
    main.cpp:3:31: error: template argument 1 is invalid
    3 |     static const int n = X<n-1>::n+n;
      |                               ^
    error: 'n' was not declared in this scope
    3 |     static const int n = X<n-1>::n+n;
      |                                    ^
 
我们可以看到，主要无非就是表达`n`还没有被声明，似乎完全不在乎**非类型模板形参`n`**?

其实倒也不是，如果你换一种写法:

```cpp
#include "iostream"
template<size_t n>
struct X{
     static const int n=n;
};
```

    main.cpp:4:29: error: declaration of 'const int n' shadows template parameter
    4 |      static const int n=n;
      |                             ^
    main.cpp:2:10: note: template parameter 'n' declared here
    2 | template<size_t n>
      |          ^~~~~~

意思无非是告诉我们，**“你不要再重复声明n了，n是一个模板形参，你看，你自己写在这里`template<size_t n>`”**

相信看多了编译器提示的开发者也很清楚这种情况，显然编译器也不清楚你到底要干嘛，就是单纯不可以而已。没啥太多的参考价值。

**扯了这么多似乎也的确有点废话了，你如果有更好的想法也可以提出来说说。**

## `msvc`有趣的返回值使用匿名结构体扩展

```cpp
#include<iostream>
struct { int max{},  min{}; } f() {
	return { 2,1 };
}

int main() {
	auto result = f();
	std::cout << result.max << ' ' << result.min << '\n';
}
```

运行结果:

    2 1

这段代码在`msvc`可以通过编译，在`gcc`和`clang`不可。

其实这个扩展可以用来解决长期以来多返回值使用结构体的问题，在 **`C++17`** 以前，`std::optional`还未诞生的时候，大家多是用下面这种写法（不要说`std::tuple`，它用`std::get<N>`毫无可读性，太卢瑟了）：

```cpp
struct factor_t {
		bool is_prime;
		long factor;
	};
factor_t factor(long n) {
	factor_t r{};
	for (long i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			r.is_prime = false;
			r.factor = i;
			return r;
		}
	}
	r.is_prime = true;
}
```

在`C++14`后，函数可以使用`auto`做返回值占位进行推导，那么倒是稍微好点，可以不用使用全局命名空间，写作下面这样：

```cpp
auto factor(long n) {
    struct factor_t {
		bool is_prime;
		long factor;
	};
	factor_t r{};
	for (long i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			r.is_prime = false;
			r.factor = i;
			return r;
		}
	}
	r.is_prime = true;
}
```

定义在局部，稍微好一些，当然最好的还是使用`C++17`的 [**`std::optional`**](https://github.com/Mq-b/Cpp20-STL-Cookbook-src#82-stdoptional-%E7%AE%A1%E7%90%86%E5%8F%AF%E9%80%89%E5%80%BC) 了。

**总而言之这个扩展是有一定的作用的，简化了一些写法，但是请清楚自己在写什么，不要在有跨平台需求的项目里使用如此写法。**

## 转换构造函数复制初始化的问题
我们可以先用一段代码引入这个问题（`《Effective Modern C++》`对此的描述有很大问题）：

```cpp
#include <iostream>
#include<atomic>

int main() {
	std::atomic<int>n = 0;
}
```
这段代码在`gcc13` `clang16`在`C++17`之前无法通过编译，`msvc`可以（这个先别管，也是个逆天）。

我相信你看到这个`=`，复制初始化，很多人就会想到是不是因为`explicit`函数的缘故：

**复制初始化不如直接初始化宽容：explicit 构造函数不是转换构造函数，也不会被复制初始化考虑。**

但是你查阅`std::atomic`的[文档](https://zh.cppreference.com/w/cpp/atomic/atomic/atomic)可以发现，它的构造函数压根没有`explicit`。

那么问题出自哪里呢？我们慢慢来，我们先写一个小`demo`：
```cpp
#include <iostream>
struct X {
	X(int){puts("int");}
    X(X&&){puts("X&&");}
    X(const X&){puts("const X&");}

};
int main() {
	X x = 1;
}
```

使用 `gcc`编译器 **`-std=c++14 -fno-elide-constructors`** 你会得到如下结果：

    int
    X&&

你注意到问题所在了吗？对！转换构造函数会先用初始化器的`1`构造出一个纯右值临时对象，然后根据重载决议，选择移动构造。

所以打印了`int`和`X&&`。

那么这和我们上面的问题有啥关系呢？

```cpp
atomic( const atomic& ) = delete;
```

我们可以看到`std::atomic`有一个弃置的复制构造函数。

**“为啥啊？不是重载决议会选择移动构造吗？”**

对，你想的很对，但是有没有一种可能，编译器根本不会为你生成移动构造？复制构造虽然是一个弃置的，但是它也是函数定义，会抑制编译器生成移动构造，你忘记了 **3 5 0**法则了吗？

**因为用户定义的析构函数、复制构造函数或复制赋值运算符的存在会阻止移动构造函数和移动赋值运算符的隐式定义。**

不要不把弃置不当用户定义的函数。

那么问题是不是就迎刃而解了？`std::atomic`没有移动构造和复制构造，没办法接纯右值临时对象来构造。

那么问题又来了，我为什么前面要强调是 **`C++17`** 之前呢？

**`C++17`** 有什么改动？**强制的复制消除**。`C++17`后可以通过编译。

但是这真的是对的吗？不对，完全不对，这不符合语意，一码归一码，就算你复制消除可以消除掉纯右值构造对象这个过程，但是这不代表你可以不需要那些函数。

这实际上可以认为是编译器的`BUG`目前。

# 总结

实际上本文暂时是这样的，后序还会看情况慢慢更新。毕竟说实在的，这种不同编译器的不同行为，数不胜数。

