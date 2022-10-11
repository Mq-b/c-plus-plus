#include<iostream>
#include<xlnt/xlnt.hpp>
#include<__msvc_all_public_headers.hpp>
#include<__msvc_chrono.hpp>

int main() {
	xlnt::workbook wb;
	//创建1个表格,注意使用active_sheet是返回一个活跃的工作表，无法多创建
	wb.active_sheet().title("data_2");
	//根据title打开工作表
	auto ws = wb.sheet_by_title("data_2");
	ws.cell("A1").value(2);

	//使用create_sheet()方法才可创建多个工作表
	wb.create_sheet().title("data_1");
	auto ws2 = wb.sheet_by_title("data_1");
	ws2.cell("A1").value(1);

	wb.save("test_data.xlsx");
}