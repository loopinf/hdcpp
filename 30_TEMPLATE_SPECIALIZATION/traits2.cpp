#include <iostream>
// T가 포인터인지 조사하는 기술
template<typename T> struct is_pointer
{
	enum { value = false}; // why enum
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