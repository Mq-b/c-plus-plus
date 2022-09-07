export module library;

import<ranges>;
/*一次导出整个命名空间*/
export namespace My{
	template<std::ranges::range Range, typename ValueType>
	constexpr void iota(Range& r, ValueType value)noexcept {
		auto iota_iter =
			[]<std::ranges::range Range>(
				auto self, Range & sub, ValueType & value
				)constexpr noexcept -> void {
			for (auto& i : sub) {
				using SubRange = std::ranges::range_value_t<Range>;
				if constexpr (
					std::ranges::range<SubRange> &&
					!std::is_convertible_v<SubRange, ValueType>
					) {
					self(self, i, value);
				}
				else {
					i = value;
					++value;
				}
			}
		};
		iota_iter(iota_iter, r, value);
	}
}