#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = {1,3,5,7,9,2,4,6,8,10};
	std::vector<int> vv = {1,3,5,7,9,2,4,6,8,10};
	std::vector<int> vvv = {1,3,5,7,9,2,4,6,8,10};

	// 아래 코드를 평가해 보세요
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
						// sort(iterator, iterator, AAA type)
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
						// sort(iterator, iterator, BBB type)
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
						// sort(iterator, iterator, CCC type)

	// if same lambda expression is used, it is better to use function object
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(vv.begin(), vv.end(), cmp);
	std::sort(vvv.begin(), vvv.end(), cmp);
	//  if < is needed, it is better to use std::less<>
	std::sort(v.begin(), v.end(), std::less<int>());
}

