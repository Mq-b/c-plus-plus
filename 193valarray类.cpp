//#include<iostream>
//#include<valarray>
//
//void test01()
//{
//	std::valarray<int> arry = { 10,20,30,40,50 };
//	std::cout << arry.size() << " " << arry.max()<<" " << arry.min() <<" " << arry.sum() << std::endl;
//	//遍历
//	for(int i : arry) {
//		std::cout << i << " ";
//	}
//	//valarray还重载了所有的算数运算符，可以不需要像stl那么麻烦的操作，直接就能给每个元素*对应的数
//	arry = arry * 10;
//	for (int i : arry) {
//		std::cout << i << " ";
//	}
//}
//void test02()
//{
//	int v = 0;
//	//构造函数，开辟10个元素的内存
//	std::valarray<int>av(10);
//	for (auto& i : av) {
//		i = v++;
//	}
//	//求和
//	std::cout << av.sum() << std::endl;
//	//重新指定内存元素个数和值，求和
//	av.resize(20, 10);
//	std::cout << av.sum() << std::endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}
////它的作用还有很多，可以看c++ prime plus583面
