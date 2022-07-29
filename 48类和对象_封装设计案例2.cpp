//#include<iostream>
//#include<math.h>
////#include"class.h"
//using namespace std;
//
////点和圆关系案例
//
////点类
//class Point
//{
//public:
//	//设置x
//	void setX(int x)
//	{
//		m_x = x;
//	}
//	//获取x
//	int getX()
//	{
//		return m_x;
//	}
//	//设置y
//	void setY(int y)
//	{
//		m_y = y;
//	}
//	//获取y
//	int getY()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//
////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//private:
//	int m_R;//半径
//
//	//在类可以让另一个类作为本来中的成员
//	Point m_Center;//圆心
//};
//
////判断点和圆关系
//void isinCircle(Circle& c, Point& p)
//{
//	//计算两点之间的距离，平方
//	int distance= pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getX() - p.getX()), 2);
//	//计算半径的平方
//	int rDistance = pow((c.getR()), 2);
//	if (distance == rDistance)cout << "点在圆上" << endl;
//	else if (distance > rDistance)cout << "点在圆外" << endl;
//	else cout << "点在圆内" << endl;
//}
//int main()
//{
//	Circle c;
//	c.setR(10);//半径
//	Point center;
//	center.setX(10);
//	center.setY(10);
//	c.setCenter(center);//给圆心赋值x轴和y轴
//	//创建点
//	Point p;
//	p.setX(10);
//	p.setY(10);
//	//判断关系
//	isinCircle(c, p);
//	return 0;
//}