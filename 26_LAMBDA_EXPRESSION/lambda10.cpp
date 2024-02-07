#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T, typename F>
void mysort(T first, T last, F op)
{
}

int main()
{
	auto f1 = [](int a, double b) { return a; };
	auto f2 = [](int a, double b) { return a + b; };
	// auto f3 = [](int a, double b)
	// { if (a == 0) return a; return b; }; // error 
	// 									// return type is not same

	auto f3 = [](int a, double b) -> double { if (a == 0) return a; return b; }; // ok
}
