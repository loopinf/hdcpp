// 5번 복사
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

    // reference capture
	auto f1 = [&v1, &v2](int a) { v1=100; return a + v1 + v2; };  // ok
    f1(0);

    std::cout << v1 << std::endl; // 100
	// ---------------------------
	class CompilerGeneratedName
	{
		int& v1; 
        int& v2;

	public:
		CompilerGeneratedName(int& a, int& b) : v1{a}, v2{b} {}

		inline int operator()(int a) const // <== mutable lambda () operator is non-const
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName{v1, v2};
}




