//#include<iostream>
//using namespace std;
//
////设计立方体类
////求立方体的面积和体积
////分别用全局函数和成员函数判断两个立方体是否相等
//class Cube
//{
//public:
//
//	//设置长
//	void setl(int l)
//	{
//		m_L = l;
//	}
//	//获取长
//	int getL()
//	{
//		return m_L;
//	}
//	//设置宽
//	void setw(int i)
//	{
//		m_V = i;
//	}
//	//获取宽
//	int setwl()
//	{
//		return m_V;
//	}
//	//设置高
//	void seth(int h)
//	{
//		m_H = h;
//	}
//	//获取高
//	int sethl()
//	{
//		return m_H;
//	}
//	//获取立方体面积
//	int calculates()
//	{
//		return 2 * m_L * m_H + 2 * m_L * m_H + 2 * m_L * m_H;
//	}
//	//获取立方体体积
//	int calculateh()
//	{
//		return m_L * m_V * m_H;
//	}
//
//	//利用成员函数判断两个立方体是否相等
//	bool iSameByCalss(Cube &c)
//	{
//		if (m_L == c.getL() && m_V == c.setwl() && m_H == c.sethl())
//			return true;
//		else return false;
//	}
//private:
//	int m_L;//长
//	int m_V;//宽
//	int m_H;//高
//	//属性
//};
//
////利用全局函数判断两个立方体是否相等
//bool isSame(Cube& c1, Cube& c2)
//{
//	if (c1.getL() == c2.getL() && c1.setwl() == c2.setwl() && c1.sethl() == c2.sethl())
//		return true;
//	else return false;
//}
//int main()
//{
//	Cube C1;
//	C1.setl(10);
//	C1.setw(10);
//	C1.seth(10);
//	cout << "立方体面积=" << C1.calculates() << endl;
//	cout << "立方体体积=" << C1.calculateh() << endl;
//
//	//创建第二个
//	Cube C2;
//	C2.setl(10);
//	C2.setw(10);
//	C2.seth(10);
//	//利用全局函数判断
//	bool ret = isSame(C1, C2);
//	if (ret)
//	{
//		cout << "c1和c2是相等的" << endl;
//	}
//	else   cout << "c1和c2是不相等的" << endl;
//
//	//利用成员函数判断
//	ret = C1.iSameByCalss(C2);//C1调用，只需要传C2进行比较
//	if (ret)
//	{
//		cout << "c1和c2是相等的" << endl;
//	}
//	else   cout << "c1和c2是不相等的" << endl;
//	return 0;
//}
