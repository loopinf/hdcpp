#include <iostream>
#include <vector>
#include <list>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 배열은 연속된 메모리 이므로
	// 배열의 시작 주소를 알면 모든 요소를 열거(++ 사용)할수 있습니다
	int* p1 = x;
	++p1;

	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	// list not 연속된 메모리 이므로
	// 배열의 시작 주소를 알면 모든 요소를 열거(++ 사용)할수 있습니다
	// even though start address is known, ++ is not possible

	// but list has iterator
	auto p2 = s.begin(); // list 의 시작 주소를 반환

	// p2 is not real pointer but ++ and dereference is possible

	std::cout << *p2 << std::endl; // 1
	// iterator is same usge   like a pointer 
	


}

