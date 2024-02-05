#include <iostream>
#include <vector>
int x = 0;

int  foo() { return x; } 
int& goo() { return x; } 

int main()
{
	// foo() = 20; 
	goo() = 20; 
	std::cout << &goo() << std::endl;
	std::cout << x << std::endl;
	// key point
	std::vector<int> v(10);
	v[0] = 10; // v.operator[](0) = 10;
}
