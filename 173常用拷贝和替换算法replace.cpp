//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用的拷贝和替换算法 replace
//class MyPrint
//{
//public:
//	void operator()(int v)
//	{
//		cout << v << " ";
//	}
//};
//void test01()
//{
//	vector<int>v;
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(50);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(10);
//
//	cout << "替换前" << endl;
//	for_each(v.begin(), v.end(), MyPrint());
//	cout << endl;
//	cout << "替换后" << endl;
//
//	//将20替换为200
//	replace(v.begin(), v.end(), 20, 200);//四个参数，不傻都看的懂
//	//把所有值为20的元素替换为200
//	for_each(v.begin(), v.end(), MyPrint());
//
//}
//
//int main()
//{
//	test01();
//	return 0;
//}

////自定义数据类型
//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//#include<vector>
//
//class Person
//{
//public:
//	Person() = default;
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//	bool operator==(const Person& val)//二元谓词
//	{
//		return this->m_Age == val.m_Age;
//	}
//	void operator=(const Person& p)//重载=
//	{
//		this->m_Age = p.m_Age;
//	}
//};
//class Print
//{
//public:
//	void operator()(const Person& p)
//	{
//		cout << "姓名:" << p.m_Name << " 学号:" << p.m_Age << endl;
//	}
//};
//void test01()
//{
//	Person p1("a", 1);
//	Person p2("b", 3);
//	Person p3("c", 4);
//	Person p4("d", 1);
//	Person p5("e", 1000);
//
//	vector<Person>n;
//	n.push_back(p1);
//	n.push_back(p2);
//	n.push_back(p3);
//	n.push_back(p4);
//
//	cout << "修改前" << endl;
//	for_each(n.begin(), n.end(), Print());//仿函数
//
//	cout << "修改后" << endl;
//	replace(n.begin(), n.end(), p4, p5);
//	for_each(n.begin(), n.end(), Print());//仿函数
//}
//int main()
//{
//	test01();
//	return 0;
//}