////提供输出迭代器
//#include<iterator>
//#include<iostream>
////提供set容器
//#include<set>
////提供string对象
//#include<string>
////提供set_union算法
//#include<algorithm>
//void test01()
//{
//	std::set<std::string>A{ "哈哈","嗯嗯","是吗" };
//	std::set<std::string>B{ "哈哈2","嗯嗯2","是吗2" };
//	//五个参数，一二是第一个迭代器的区间，三四是第二个迭代器的区间，第五个是是输出迭代器，将复制到什么位置，我们这里选择使用输出迭代器，拷贝到输出流中匿名对象
//	//还是一样的，输出迭代器的参数得和要输出的数据类型一样，然后勇空格隔开
//	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<std::string, char>(std::cout, " "));
//}
//void test02()
//{
//	std::set<int>B{ 1,2,3,4,5 };
//	std::set<int>A{ 6,7,8,9,10 };
//	std::set<int>sum;
//
//	//唯一不同的是第五个参数我们使用匿名的insert_iterator，意思很明确就是插入_迭代器，以插入的方式放入容器，就不需要像之前copy一样先开辟内存了
//
//	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::insert_iterator<std::set<int>>(sum, sum.begin()));
//
//	//我们遍历输出看看
//	//并且我们注意到，插入到set容器的时候自动按照从小到大的降序排序好了,如果想改变排序顺序可以在创建set对象的时候传入仿函数或者普通函数
//	std::copy(sum.begin(), sum.end(), std::ostream_iterator<int, char>(std::cout, " "));
//}
//int main()
//{
//	//使用输入迭代器做第五个参数
//	//test01();
//
//	//将集合放入容器中
//	test02();
//	return 0;
//}
//还有函数set_intersection()和set_difference()分别查找交集和获得的差，它们的接口和set_union相同 