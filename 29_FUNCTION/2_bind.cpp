#include <iostream>
#include <functional>
using namespace std::placeholders;

// C++ 함수 포인터를 대신하기 위해 만든 도구 : std::bind & std::function

// std::bind : N 항 함수(객체) 를 일부 인자를 고정해서 M 항 함수로 만드는 도구
//			   (단, N >= M )

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	// foo 는 "4항 함수" : 인자의 갯수가 4개
	foo(10, 20, 30, 40);

	//  1. std::bind 사용법
		// auto f = std::bind(N항 함수, N개인자); 
	// 반환값은 새로운 함수

	auto f0 = std::bind(&foo, 10, 20, 30, 40); 
	f0();
	auto f2 = std::bind(&foo, 10, _1, 30, _2); 
	f2(8,4);
	auto f3 = std::bind(&foo, 7, _2, _1, 2);
	f3(9, 3); // "foo : 7, 3, 9, 2" 나오게 만들어 보세요	
}