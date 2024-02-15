#include <iostream>
// T가 포인터인지 조사하는 기술
template<typename T> struct is_pointer
{
	bool value = true; // 1. C++11 이전에는 이렇게 초기화 안됨
						// 2. 이렇게 하면 컴파일 시간 상수가 아닌 변수
	enum { value = false}; // why enum >> C++11 이전에는 이코드 최선
};
template<typename T> struct is_pointer<T*>
{
	enum { value = true};
};

template<typename T> 
void foo(T arg )
{
	// T : int, int*
	if ( is_pointer<T>::value )
		std::cout << "pointer\n";
	else 
		std::cout << "not pointer\n";
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}