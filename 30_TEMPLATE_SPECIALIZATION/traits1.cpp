#include <iostream>

template<typename T> 
void printv(const T& value)
{
	if ( T 가 포인터 타입 이면 )
		std::cout << value << " : " << *value << std::endl;
	else 
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}