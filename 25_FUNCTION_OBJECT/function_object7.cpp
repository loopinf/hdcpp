#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 템플릿 입니다.
	// => 사용자가 전달한 인자를 가지고 "함수를 생성" 한다는 의미.


	// 1. 비교 정책으로 일반함수 사용시
	//  pros: code memory 절약
	//        
	//  cons: inline이 안됨, cmp1, cmp2 함수가 호출되므로

	std::sort(x, x + 10, cmp1);  // sort(int*, int*, bool(*)(int, int)) 
	std::sort(x, x + 10, cmp2);


	// 2. 비교정책으로 함수객체 사용시

	// pros: cmp as many as you want, make 

	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1);  // sort(int*, int*, Less)
	std::sort(x, x + 10, f2);  // sort(int*, int*, Greater)
}









