- [前言](#前言)
  - [`C99`的变长数组(`VLA`)](#c99的变长数组vla)
    - [总结](#总结)
  - [非常量左值引用能接纯右值？](#非常量左值引用能接纯右值)
    - [总结](#总结-1)
  - [内建下标访问运算符中`msvc`违背C++标准？](#内建下标访问运算符中msvc违背c标准)
    - [总结](#总结-2)
  - [你真的懂弃置函数？`函数名()=delete`](#你真的懂弃置函数函数名delete)
  - [`lambda`表达式隐式捕获，到底谁违反了`C++`标准？](#lambda表达式隐式捕获到底谁违反了c标准)
  - [零长数组？](#零长数组)
  - [`{}`初始化，`msvc`居然遵守了规定？](#初始化msvc居然遵守了规定)


# 前言

**本文的主题很简单，就是介绍那些平时使用的时候，很容易依赖当前编译器的东西而非标准`C++`导致的各种不兼容的问题。**

这可能是因为编译器不遵守标准规定，也可能是因为编译器扩展。**注意:我们不会介绍各个编译器所有的编译器扩展，只是在一些的确容易间接依赖到的地方，才会强调。**

当然，也欢迎各位补充！

## `C99`的[变长数组(`VLA`)](https://zh.cppreference.com/w/c/language/array)

默认情况下在我们写`C++`的时候`GCC` `clang`是支持了`C`语言的这一特性，这有什么大问题吗？

不大不小。听我们往下说：下面这段[**代码**](https://godbolt.org/z/7jWh6dn1a)使用`GCC13.1`和`clang16.0`都不存在任何问题。但是当你想移植在`msvc`上，就会给你一个编译错误，这是里理所应当的，因为这的确违背了标准`C++`的规定。

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

至于`sizeof`运算符的问题，实际上按照`C++`标准规定，它肯定是常量表达式，但是呢，因为`VLA`，这一不属于`C++`的东西，那么自然这里的情况就得参见 [`C`的文档](https://zh.cppreference.com/w/c/language/sizeof)了:

    若 表达式的类型为非常量长度数组类型，则求值 表达式 ，并在运行时计算其所求值的数组大小。(C99 起)

那么运行时，自然不算常量表达式。

### 总结

好了，相信这第一个简单的问题，已经能让你意识到了一些问题，其实如果使用者真的清楚，那么利用这些兼容的扩展，清楚自己在做什么，也无伤大雅。但是更多的是大多数人不清楚自己在写什么，编译器过了就过了，包括过度依赖编译器，很多思考理解问题的方式，都有很大的问题。

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
这段代码在`msvc`下是 **`false`**，在`GCC`和`clang`都是 **`true`**

显然是`msvc`违背了规定。

### 总结

至于这又会产生一些什么`bug`或移植问题，我相信看了前面两个问题，你应该会有一些想法了，不过嘛，**数组右值使用毕竟还是比较少，可能也不算很常见**。

---

## 你真的懂[弃置函数](https://zh.cppreference.com/w/cpp/language/function)？`函数名()=delete`

以我的视角，我说一个可观的我个人认为的大概的数据，**`%95`**的人并不懂这个东西，只是会一些基本的禁止一些特殊的成员函数，仅此而已。

我们要讲这弃置函数不同编译器的一些问题，但是在此之前，我们更应该普及点基本的`C++`规定，避免错误的理解

---

## [`lambda`表达式](https://zh.cppreference.com/w/cpp/language/lambda)隐式捕获，到底谁违反了`C++`标准？

---

## 零长数组？

---

## `{}`初始化，`msvc`居然遵守了规定？
