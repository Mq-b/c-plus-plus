#include<iostream>
#include<ranges>

template<std::ranges::range Range, typename ValueType>
constexpr void iota(Range& r, ValueType value)noexcept {
	auto iota_iter =
		[]<std::ranges::range Range>(
			auto self, Range & sub, ValueType & value
			)constexpr noexcept -> void {
		for (auto& i : sub) {
			using SubRange = std::ranges::range_value_t<Range>;//获取range的元素的类型，也就是传入的序列中元素类型,四维数组那么它的元素就是三维数组
			if constexpr (/*用普通的if会在递归调用那里产生硬错误 不用的话上下都会被实例化*/
				std::ranges::range<SubRange> &&//测试SubRange是不是range，范围是对区间的抽象
				!std::is_convertible_v<SubRange, ValueType>//检查是否能转换一个类型为另一类型,这里是两个类型不能一样
				) {
				self(self, i, value);//这里是递归，直到编译期if条件不满足为止，即直到数组降到只剩下int
			}
			else {
				i = value;
				++value;
			}
		}
	};
	iota_iter(iota_iter, r, value);
}
int main() {
	int arrays[10][10][10][10];
	::iota(arrays, 0);
	std::cout << arrays[9][9][9][9] << std::endl;
}
/*7-9行和第16行的调用部分可能不是一个类型，如果不用if constexpr可能会无限生成新的类型，哪怕不执行*/