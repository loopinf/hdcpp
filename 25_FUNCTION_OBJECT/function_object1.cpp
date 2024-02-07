#include <iostream>

// 237 page ~ 

// #1. 함수 객체(function object)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체
// -=> () const function 

// why?? use function object
// 1. closure
// 2. faster than function pointer
// 3. inline 가능??
// 4. template 인자로 전달 가능
// after C++20 
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;		// p 는 함수가 아닌 객체 입니다.(Plus 타입)

	int n1 = p(1, 2); // 객체인 p를 함수 처럼 사용합니다. 함수객체 라고 합니다.
	//
	int n2 = p.operator()(1, 2); // 이것이 호출되는 것입니다.
}
