#include <iostream>
// constexpr function
// -> if arg known at compile time, return value is known at compile time
// -> if arg is not known at compile time, return value is not known at compile time
		  int add1(int a, int b) { return a + b; }
constexpr int add2(int a, int b) { return a + b; }

constexpr void foo()
{
	std::cout << "foo" << std::endl;
	int* p = new int;
}
int main()
{
	int x = 1, y = 2;

	int n1 = add1(1, 2);  // run on runtime
	int n2 = add2(1, 2);  // run on compile time
	int n3 = add2(x, y);  // run on runtime
}


// constexpr 3 types
// 1. constexpr variable
// 2. constexpr function
// 3. constexpr if
