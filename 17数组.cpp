//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num[10];
//	for (int i = 0; i < 10; i++)cin >> num[i];
//	for (int i = 0; i < 10; i++)cout << num[i] << endl;
//	return 0;
//}

//ÔªËØÄæÖÃ
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num[10] = { 0 };
//	for (int i = 0; i < 10; i++)cin >> num[i];
//	int start = 0;
//	int end = 9;
//	while (start < end)//ÄæÖÃ
//	{
//		int temp = num[start];
//		num[start] = num[end];
//		num[end] = temp;
//		start++, end--;
//	}
//	for (int i = 0; i < 10; i++)cout << num[i] << endl;
//	return 0;
//}