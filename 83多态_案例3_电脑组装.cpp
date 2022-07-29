//#include<iostream>
//using namespace std;
//
////抽象不同零件类
////抽象CPU类
//class CPU
//{
//public:
//	//抽象的计算函数
//	virtual void calculate() = 0;
//};
////抽象显卡类
//class VideoCard
//{
//public:
//	//抽象的显示函数
//	virtual void display() = 0;
//};
////抽象内存条类
//class Memory
//{
//public:
//	//抽象的存储函数
//	virtual void calculate() = 0;
//};
//
////电脑类
//class Computer
//{
//public:
//	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_mem = mem;
//	}
//
//	//提供析构函数，释放电脑零件
//	~Computer()
//	{
//		//释放CPU
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		//释放显卡
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//			m_vc = NULL;
//		}
//		//释放内存条
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//			m_mem = NULL;
//		}
//	 }
//
//	//提供工作函数
//	void word()
//	{
//		m_cpu->calculate();
//		
//		m_vc->display();
//
//		m_mem->calculate();
//	}
//private:
//	CPU* m_cpu;//cpu的零件指针
//	VideoCard* m_vc;//显卡零件指针
//	Memory* m_mem;//内存条零件指针
//};
//
////具体厂商
////intel厂商
//class intelCPU :public CPU
//{
//public:
//	virtual void calculate()//子类重写父类
//	{
//		cout << "Intel的CPU开始计算了！" << endl;
//	}
//};
//
//class intelVoideoCard :public VideoCard
//{
//public:
//	virtual void display()//子类重写父类
//	{
//		cout << "Intel的显卡开始显示了！" << endl;
//	}
//};
//
//class intelMemory :public Memory
//{
//public:
//	virtual void calculate()//子类重写父类
//	{
//		cout << "Intel的内存条开始存储了！" << endl;
//	}
//};
//
////Lenovo
//class LenovoCPU :public CPU
//{
//public:
//	virtual void calculate()//子类重写父类
//	{
//		cout << "Lenovo的CPU开始计算了！" << endl;
//	}
//};
//
//class LenovoVoideoCard :public VideoCard
//{
//public:
//	virtual void display()//子类重写父类
//	{
//		cout << "Lenovo的显卡开始显示了！" << endl;
//	}
//};
//
//class LenovoMemory :public Memory
//{
//public:
//	virtual void calculate()//子类重写父类
//	{
//		cout << "Lenovo的内存条开始存储了！" << endl;
//	}
//};
//
//void test01()
//{
//	//第一台电脑的零件
//	CPU* intelcpu = new intelCPU;
//	VideoCard* intelCard = new intelVoideoCard;
//	Memory* intelMem = new intelMemory;
//
//	//创建第一台电脑
//	Computer* computer = new Computer(intelcpu, intelCard, intelMem);
//	computer->word();
//	delete computer;
//
//	cout<<"------------------------------------"<<endl;
//	cout << "第二台电脑开始工作" << endl;
//	//创建第二台电脑
//	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVoideoCard, new LenovoMemory);
//	computer2->word();
//	delete computer2;
//}
//int main()
//{
//	test01();
//	return 0;
//}