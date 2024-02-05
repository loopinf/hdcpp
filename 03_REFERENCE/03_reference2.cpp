// pointer vs reference
#include <iostream>
int main()
{
	int  n = 10;

	// #1. 초기화 하는 방법
	int* p1 = &n;
	int& r1 = n;

	int* p2;  // no init possible.
	// int& r2;  // error. 
	
	// #2. 대상체(n) 에 접근
	*p1 = 20;
	r1  = 20;
	
	// #3. 
	int n2 = 20;
	p1 = &n2;   // p1 point to different 
	r1 = n2;

	std::cout << r1 << std::endl; 
	std::cout << &r1 << std::endl; 
	std::cout << &p1 << std::endl;

}

// pointer 보다 reference 가 안전 하다.

void f1(int* p)
{
	*p = 10;
}

void f2(int& r)
{
	r = 10;
}