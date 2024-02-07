// 아래 주석의 의미를 잘생각해 보세요

// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.

// 2. function object : has its own type
//    signature same but all function object has its own type

//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.
#include <iostream>
#include <algorithm> 
struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

// void Sort(int* x, int sz, bool(*cmp)(int, int) )
template<typename T>
void Sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if ( cmp(x[i], x[j]))
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; 
	std::cout << f1(1, 2) << std::endl;
	Sort(x, 10, f1);
	Greater f2; f2(1, 2); Sort(x, 10, f2);

}



