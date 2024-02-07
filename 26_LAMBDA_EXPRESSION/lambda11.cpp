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
	int v1 = 10, v2 = 10;

	auto f1 = [v1, &v2]() {}; // v1 is captured by value, v2 is captured by reference
	auto f2 = [=] () {};      // all local valirable are captured by value
	auto f2 = [&] () {};      // all local valirable are captured by reference

	auto f4 = [=, &v1]() {};  // all local valirable are captured by value, except v1 is captured by reference
	auto f5 = [&, v1]() {};   // all local valirable are captured by reference, except v1 is captured by value
	auto f6 = [&, &v1]() {};  // all local valirable are captured by reference, except v1 is captured by reference

	auto f7 = [a = v1, &b = v2]() {}; // a is captured by value, b is captured by reference
			// int   a = v1; // a is captured by value
			// int & b = v2; // b is captured by reference


}
