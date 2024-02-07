#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

class IsDivide
{
	int value;

public:
	IsDivide(int n) : value(n) {}
	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = {1, 2, 6, 5, 4, 3, 7, 8};

	// 주어진 구간에서 "k의 배수"를 찾고 싶다.
	int k = 3;
	// auto p1 = std::find_if(v.begin(), v.end(), foo);
	IsDivide f{k}; // f captures k
	bool b = f(7); // 7 % k == 0

	// auto p1 = std::find_if(v.begin(), v.end(), f);
	auto p1 = std::find_if(v.begin(), v.end(), IsDivide{k});
	int k = 0;
	std::cin >> k;
}

// closure
// => context , main 함수의 지역변수 k를 캡쳐해서 사용한다.
// normal function : no state, only method-> no closure
// function object : state, method        -> closure