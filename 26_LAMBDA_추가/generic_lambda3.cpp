#include <iostream>

int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = a; a = b; b = tmp;};

	int n1 = 10, n2 = 20;
	swap(n1, n2);

	double d1 = 2.1;
	swap(n1, d1);        // int, double 을 swap 
						// C++20 부터 template lambda is introduced
	auto swap2 = []<typename T>(T&a, T& b){ T tmp = a; a = b; b=tmp;};

	
}