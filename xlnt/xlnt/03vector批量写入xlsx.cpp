#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <string>



int main(){
	std::vector< std::vector<std::string> > wholeWorksheet;
	for (int outer = 0; outer < 10; outer++){
		std::vector<std::string> singleRow;
		for (int inner = 0; inner < 10; inner++){
			//给vector中的每个元素赋值
			singleRow.emplace_back(std::to_string(inner + 1));
		}
		wholeWorksheet.emplace_back(singleRow);
	}
	//创建工作簿
	xlnt::workbook wbOut;

	//创建工作表，并把vector中的元素写入表格
	xlnt::worksheet wsOut = wbOut.active_sheet();
	//给工作表设置名称
	wsOut.title("data");
	for (int fOut = 0; fOut < wholeWorksheet.size(); fOut++){
		for (int fIn = 0; fIn < wholeWorksheet.at(fOut).size(); fIn++){
			std::string cell = xlnt::cell_reference(fIn + 1, fOut + 1).to_string();
			// 给单元格赋值。特别注意：工作表中的单元格下标是从1开始，而vector中的元素下标是从0开始
			wsOut.cell(cell).value(std::stoi(wholeWorksheet[fOut][fIn]));
			//将单元格格式设置为数字.00格式
			wsOut.cell(cell).number_format(xlnt::number_format::number_00());
		}
	}
	wbOut.save("test_save.xlsx");
}
//需要注意，如果设置单元格value的时候使用的是string，那么不管再设置什么格式都是无效的，都只是文本格式