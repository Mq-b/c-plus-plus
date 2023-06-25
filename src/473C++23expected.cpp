#include<iostream>
#include<expected>

std::expected<int, std::errc>f(bool b) {
	if (b)return { 1 };
	else return std::unexpected(std::errc::address_in_use);
}

int main() {
	auto result = f(false);
	if (result)
		std::cout << *result << '\n';
	else
		std::cout << static_cast<int>(result.error()) << '\n';
}