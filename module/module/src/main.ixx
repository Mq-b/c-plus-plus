import Module;//引入模块
import library;
import<iostream>;
int main() {
	int arrays[10][10][10][10];
	My::iota(arrays, 0);
	std::cout << arrays[9][9][9][9] << std::endl;
}