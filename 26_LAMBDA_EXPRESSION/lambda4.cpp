#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };
	int k = 3;
	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	auto p1 = std::find_if(v.begin(), v.end(), 
				[k](int n){ return n % k ==0;} 
				);	



}



