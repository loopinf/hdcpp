#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// auto f1 = [v1, v2](int a) { return a + v1 + v2; };  // ok

	// auto f1 = [v1, v2](int a)     { v1 = 100; return a + v1 + v2; };
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok

	f1(0);

	std::cout << v1 << std::endl; // 10
	// ---------------------------
	// class CompilerGeneratedName
	// {
	// 	int v1, v2;

	// public:
	// 	CompilerGeneratedName(int a, int b) : v1{a}, v2{b} {}
	// 	inline int operator()(int a) //const <== mutable lambda () operator is non-const
	// 	{
	// 		v1 = 100;
	// 		return a + v1 + v2;
	// 	}
	// };
	// auto f2 = CompilerGeneratedName{v1, v2};
}