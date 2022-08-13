//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(vector<int>v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	vector<int>v1;
//	//尾插
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	printVector(v1);`
//
//	//尾删
//	v1.pop_back();
//	printVector(v1);
//
//	//插入 第一个参数是迭代器，意味着插入到最前面
//	v1.insert(v1.begin(), 100);
//	printVector(v1);
//
//	v1.insert(v1.begin(), 2, 100);//重载版本，从第一个迭代器的位置插入2个100
//	printVector(v1);
//
//	//删除
//	v1.erase(v1.begin());//参数迭代器
//	printVector(v1);
//
//	//类似清空
//	v1.erase(v1.begin(), v1.end());//删除区间所有的
//	printVector(v1);
//
//	//清空
//	v1.clear();
//	printVector(v1);
//
//}
//int main()
//{
//	test01();
//	return 0;
//}
///*
//尾插--push_back
//尾删--pop_back
//插入--insert(位置迭代器)
//清空--clear
//*/