module;
export module A:imp2;
import<iostream>;

export void print(auto t) {
	std::cout << t << '\n';
}
template<>
void print<int>(int t) {
	std::cout << "print int\n";
}