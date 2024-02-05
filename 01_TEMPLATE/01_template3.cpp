#include <iostream>

template <typename T1, typename T2>
// T? Add(T1 a, T2 b)    return type deduction?? 
// T? Add(T1 a, T2 b)
T Add(T a, T b)
{
	return a + b;
}
{
	return a + b;
}

int main()
{
	std::cout << Add<double>(1,   2.1 ) << std::endl;
	// std::cout << Add(1,   2.1 ) << std::endl;
	std::cout << Add(1,   2 ) << std::endl;
	std::cout << Add(1.1, 2.2) << std::endl;

					// => 컴파일 에러는 아니지만 데이타 손실 발생
}

