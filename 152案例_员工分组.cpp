//#include<iostream>
//using namespace std;
//#include<vector>//提供vector容器
//#include<string>//提供string容器
//#include<map>//提供multimap容器
//#include<ctime>//提供真随机数
//enum ave//使用枚举要比宏定义简洁
//{
//	CEHUA, MEISHU, YANFA//策划 美术 研发
//};
////#define CEHUA 0//策划
////#define MEISHU 1//美术
////#define YANFA 2//研发
//class Worker
//{
//public:
//	string m_Name;
//	int m_Salary;
//};
////给初始员工容器赋值
//void creatoWorker(vector<Worker>& v)
//{
//	string nameSeed = "ABCDEFGHJK";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.m_Name = "员工";
//		worker.m_Name += nameSeed[i];//给员工名字赋值
//
//		worker.m_Salary = rand() % 10000 + 10000;//10000~19999 给员工工资赋值
//		//将员工放入到容器中
//		v.push_back(worker);
//
//	}
//}
////员工分组
//void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
//{
//	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		//产生随机部门的编号
//		int depId = rand() % 3;//0 1 2
//
//		//将员工插入到分组中
//		//key代表部门的编号，value代表具体员工
//		m.insert(make_pair(depId ,*it));//multimap m容器接收到分组和v容器的值
//
//	}
//}
////显示员工
//void showWorkerByGourp(multimap<int,Worker>&m)
//{
//	//0 A B C 1 D E 2 F G...
//	cout << "策划部门:" << endl;
//
//	multimap<int,Worker>::iterator pos = m.find(CEHUA);//m查找key为0的地址，赋值给pos迭代器
//	int count = m.count(CEHUA);//统计策划部门具体人数
//	int index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		//pos迭代器是multimap<int,Worker>类型的，first是key 索引，second是value 值；所以得pos指向second就是value的值,自定义数据类型.来取值
//		cout << "姓名:" << pos->second.m_Name << " 工资:" << pos->second.m_Salary << endl;
//	}
//
//	cout << "--------------------" << endl;
//	cout << "美术部门" << endl;
//	//pos,count,index不用重新创建了
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU);
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "姓名:" << pos->second.m_Name << " 工资:" << pos->second.m_Salary << endl;
//	}
//
//	cout << "--------------------" << endl;
//	cout << "研发部门" << endl;
//	pos = m.find(YANFA);
//	count = m.count(YANFA);
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "姓名:" << pos->second.m_Name << " 工资:" << pos->second.m_Salary << endl;
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));//随机数种子
//
//	//1.创建员工
//	vector<Worker>vWorker;
//	creatoWorker(vWorker);
//
//	//2.员工分组
//	multimap<int, Worker>mWorker;
//	setGroup(vWorker, mWorker);
//
//	//3.分组显示员工
//	showWorkerByGourp(mWorker);
//	////测试
//	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
//	//{
//	//	cout << "姓名=" << it->m_Name << "工资" << it->m_Salary << endl;
//	//}
//	return 0;
//}