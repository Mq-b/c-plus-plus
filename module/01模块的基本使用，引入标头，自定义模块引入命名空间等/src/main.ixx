import Module;//引入模块
import library;
import<iostream>;
import<array>;
import<ranges>;

int main() {
	int arrays[10][10][10][10];
	My::iota(arrays, 0);
	std::cout << arrays[9][9][9][9] << std::endl;

	std::array arr{ 1,2,3,4 };
	for (const auto i : arr) {
		std::cout << i << '\n';
	}
}