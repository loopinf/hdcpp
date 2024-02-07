#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// #1. 모든 람다 표현식은 다른 타입 입니다.
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	auto f3 = [](int a, int b) { return a + b; };
}
