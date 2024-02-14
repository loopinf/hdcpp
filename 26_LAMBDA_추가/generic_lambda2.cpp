#include <iostream>

class CompilerGeneratedName 
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const 
	{
		return a + b;
	}
};

int main()
{
// 아래 한줄 보고 컴파일러가 위 클래스를 생성함
//	auto add = [](auto a, auto b) { return a + b;};

	auto add = CompilerGeneratedName();
}

