#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T, typename F>
void mysort( T first, T last, F op)
{
}

int main()
{
	std::vector<int> v = {1,3,5,7,9,2,4,6,8,10};

	// 아래 코드를 평가해 보세요
	mysort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	mysort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	mysort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}


