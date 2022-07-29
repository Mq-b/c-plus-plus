//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class T>void func(const T&)
//{
//	cout << "const T &" << endl;
//}
//
//template<class T>void func(T&)
//{
//	cout << "T &" << endl;
//}
//
//template<class T>void func(T&&)
//{
//	cout << "T &&" << endl;
//}
//
//template<class T>void forward_val(T &&temp)//参数为右值引用
//{
//	//保存参数的左值右值属性
//	func(std::forward<T>(temp));
//}
//
//int main()
//{
//	int a = 0;
//	const int& b = 1;
//	forward_val(a);//T &
//	forward_val(b);//const T &
//	forward_val(111);//const T &&
//	forward_val(std::move(10));//const T &&		这两个相同的，加不加move都是右值
//	return 0;
//}
