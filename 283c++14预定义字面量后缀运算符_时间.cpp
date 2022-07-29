#include<chrono>
#include<ratio>
#include<iostream>
#include <thread>
using namespace std::chrono_literals;
int main() {
	auto house = 24h;
	auto min = 60min;
	auto ms = 60ms;
	auto a = std::chrono::system_clock::now();
	std::cout << a<< std::endl;
	std::this_thread::sleep_for(1s);
	std::cout << std::chrono::system_clock::now()-a << std::endl;
}