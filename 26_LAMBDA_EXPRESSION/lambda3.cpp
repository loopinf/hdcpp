#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = {1,3,5,2,4,6};

	// 람다 표현식 활용 1. STL 알고리즘의 인자로 사용
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	
	// 람다 표현식 활용 2. auto 변수에 담아서 함수 처럼 사용

	auto f = [](int a, int b) { return a + b;};
	// class xxx{ operator()(){}}; xxx{};
	int n1 = f(1,2);
	int n2 = f(3,4);

}

	