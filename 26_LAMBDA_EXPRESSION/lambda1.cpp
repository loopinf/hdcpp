#include <iostream>
#include <algorithm>
#include <functional> // std::less<>, std::greater<> 가 이미 있습니다.(C++98)
#include <vector>

// 248 page ~ 

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	
	// #1. 비교 policy 를 전달하지 않은 경우 - 오름차순으로 정렬
	std::sort( v.begin(), v.end() );  // 1,2,3,4,5,6,7,8,9,10

	// #2. normal func, inline not possible
	std::sort( v.begin(), v.end(), cmp );  // 1,2,3,4,5,6,7,8,9,10

	// #3. function object
	// std::less<int> f;
	// std::sort( v.begin(), v.end(), f);

	std::sort( v.begin(), v.end(), std::less<int>{});
	// #4. lambda express
	std::sort( v.begin(), v.end(), [](int a, int b){return a> b;});

	// compiler will do below
	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const 
		{ return a > b; }
	};

	std::sort( v.begin(), v.end(), CompilerGeneratedName{});
	// lambda expression : 
	// 1. function object 


}





