#include <iostream>
#include <xlnt/xlnt.hpp>

int main()
{
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();

	//设置工作表名称
	ws.title("data");
	//赋值为数值
	ws.cell("A1").value(0.5);
	//设置单位格格式，设为百分比形式
	ws.cell("A1").number_format(xlnt::number_format::percentage());
	//赋值为字符串
	ws.cell("B2").value("string data");
	//赋值为公式
	ws.cell("C3").formula("=RAND()");
	//合并单元格
	ws.merge_cells("C3:C4");
	//冻结窗格
	ws.freeze_panes("B2");
	//保存
	wb.save("test_save.xlsx");
}