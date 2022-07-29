//#include<iostream>
//#include<string>
//#include<ctime>
//using namespace std;
//struct students
//{
//	string name;
//	int score;
//};
//struct teacher
//{
//	string name;
//	students stu[5];
//};
//
//void dat(teacher* p, int num)
//{
//	string namea = "ABCDE";
//	for (int i = 0; i < num; i++)
//	{
//		p[i].name = "teacher";
//		p[i].name += namea[i];
//		for (int j = 0; j < 5; j++)
//		{
//			p[i].stu[j].name = "student";
//			p[i].stu[j].name = namea[j];
//			p[i].stu[j].score = rand()%100;
//		}
//	}
//}
//
//void print(teacher* p, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		cout << "老师:" << p[i].name << endl;
//		for (int j = 0; j < 5; j++)
//		{
//			cout << p[i].stu[j].name <<"\t" << p[i].stu[j].score<<endl;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));//随机数种子
//	teacher s1[3];
//	int num = sizeof(s1) / sizeof(s1[0]);
//	dat(s1, num);
//	print(s1, num);
//	return 0;
//}