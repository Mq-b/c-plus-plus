#include <iostream>
#include <xlnt/xlnt.hpp>
#include<vector>
#include<vector>
#include<string>

int main(){
	std::vector<std::vector<std::string>>value{};
	xlnt::workbook wb;//创建一个工作簿对象
	wb.load("test.xlsx");
	auto ws = wb.active_sheet();//返回工作表对象

	// 会把当前占用的单元格全都打印出来，空单元格则为空格。
	for (auto row : ws.rows(false)){
		std::vector<std::string>tmp{};
		for (auto cell : row) {
			tmp.emplace_back(cell.to_string());
			std::clog << cell.to_string() << "\t";
		}
		value.emplace_back(tmp);
		std::clog << std::endl;
	}
	std::cout << "---------------------------------------------\n";
	for (auto i : value) {
		for (auto j : i) {
			std::cout << j << '\t';
		}
		std::endl(std::cout);
	}
}
