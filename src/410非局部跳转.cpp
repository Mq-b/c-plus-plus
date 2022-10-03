#include <iostream>
#include <csetjmp>

std::jmp_buf jump_buffer;

__declspec(noreturn) void a(int count)//__declspec是MSVC编译器扩展，这里noreturn等价于标准库的[[noreturn]]
{
	std::cout << "a(" << count << ") called\n";
	std::longjmp(jump_buffer, count + 1);  // 加载先前的 setjmp 调用所保存的执行环境 env 。此函数不返回。
}

int main()
{
	volatile int count = 0; // 在 setjmp 作用域中被修改的局部变量必须是 volatile
	if (setjmp(jump_buffer) != 9) { // setjmp 返回传递给 std::longjmp 的值
		a(++count);
	}
}