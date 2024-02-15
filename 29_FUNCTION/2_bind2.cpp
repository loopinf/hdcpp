#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	auto f0 = std::bind(&foo, 10, 20, 30, 40); 
	auto f2 = std::bind(&foo, 10, _1, 30, _2); 
	// #1. std::bind 의 반환 타입은 어떻게 사용하는 가
	// => 그래서 auto로 받아야
	// => f0, f2 는 다른 타입
	// => 단, f0, f2 모두 operator() 연산자가 재정의된 함수객체입니다. 
	// 		그래서 ()로 호출가능


	// f2 = std::bind(&foo, 0,0,0,0);  // error
	std::cout << typeid(f0).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}