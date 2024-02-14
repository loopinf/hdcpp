#include <iostream>

template<typename T> 
void foo(T arg )
{
	if ( ? )
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