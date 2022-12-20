module;//全局模块片段,主要为了使用预处理指令序列的，我们完全用不到
export module A:imp1;
import<iostream>;
import :imp2;

export void MyFunc() {
	std::cout << "666\n";
}