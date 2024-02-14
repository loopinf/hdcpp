#include <iostream>

// 인자로 auto를 사용하는 코드
// C++14 : lambda expression only
// C++20 : 일반 함수 에서도 사용 가능

auto add1(auto a, auto b)
{
	return a+ b;
}


int main()
{
	// auto add = [](int a, int b) { return a + b;};
	auto add = [](auto a, auto b) {return a+b;};

	std::cout << add(1,   2)   << std::endl;
	std::cout << add(1.1, 2.1) << std::endl;
	std::cout << add(1,   2.1) << std::endl;
	std::cout << add(1.1, 2)   << std::endl;
	
}