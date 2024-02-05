#include <iostream>

int main()
{
	const int c = 10;

	// int* p = &c;    // error, const

	int* p = (int*)&c;
	*p = 20;
	std::cout << c << std::endl;
}
