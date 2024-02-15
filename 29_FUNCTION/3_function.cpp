#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a) {}
void f2(int a, int b) {}

struct Dialog 
{	
	void close(int code) {} 
};

int main()
{
	// 1. 함수 포인터는 signature 동일한 함수 주소만 담을 수 있음
	// void(*f)(int); 
	// f = &f1; //ok
	// f = &f2; // error

	// 2. std::function 은 함수 포인터를 대신하기 위해 만든 C++ 도구 (STL)
	// 사용법: std::function<함수 타입> f;

	// void(*)(int) : 함수 포인터 타입
	// void   (int) : 함수 타입

	std::function<void(int)> f;
	f = &f1;
	f(10); // f1(10) 의 의미임

	// 2. std::function 의 장점
	// => std::bind 의 결과를 보관 가능

	// f = &f2; // error

	f = std::bind(&f2, _1, 0); // ok. std::bind 사용 2항->1항 변경후 담으면 됨

	f(3); // f2(3, 0)

	// 3. std::bind 덕분에 멤버함수도 f에 담을 수 있음
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1);
	f(10);
}
// 정리
// std::bind       : 함수(객체)의 인자를 고정한 새로운 함수를 만드는 도구
// std::function   : 함수주소, 람다표현식, std::bind의 결과를 보관할 수 있는 도구