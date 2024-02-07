// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };


	// 1. 반복자의 정확한 타입
	// => "컨테이너이름::iterator"

	std::list<int>::iterator p1 = s.begin(); 
	auto p2 = s.begin(); 
	std::cout <<  typeid(p2).name() << std::endl; // std::_List_iterator<int, int&, int*>
	
}







/*
namespace std
{
	template<typename T>
	class list
	{
	public:
		class iterator
		{
		};
	};
}
*/