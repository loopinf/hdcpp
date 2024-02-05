// 64 page ~
#include <iostream>
#include <array>
int main()
{
	int n = 0;
	// std::cin >> n;

	const int c1 = n;
	const int c2 = 3;

	// constexpr int c3 = n;
	constexpr int c4 = 3;

	int k1 = c1;  // c1 memory
	int k2 = c4;

	std::array<int, 10> arr1;  // c2 memory
	// std::array<int, c1> arr2;  // c2 memory
	std::array<int, c2> arr3;  // c2 memory
	std::array<int, c4> arr4;  // c4 memory
}