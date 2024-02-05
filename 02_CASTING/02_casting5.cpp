#include <iostream>

// reinterpret_cast   ONLY 2 PURPOSE
// 1. 서로 다른 타입 끼리의 주소 변환
// 2. 정수 <=> 포인터 사이의 변환
// memory interpretation -- re inter pret

int main()
{
	int n =  10; 

	// #1. 서로 다른 타입의 주소 변환
	// double* p1 = static_cast<double*>(&n);  // error
	// double* p1 = (double*)&n; // usually success, but danger.
	double* p1 = reinterpret_cast<double*>(&n);  // error



	// #2. 정수 <=> 포인터 변환
	// int* p2 = 10;  // error
	int* p2 = (int*)10;
	// int* p2 = static_cast<int*>(10); // error
	int* p2 = reinterpret_cast<int*>(10); // address 10, do something...

	// address => integer
	// int  n = p2; // error
	// int n = static_cast<int>(p2);
	int n = reinterpret_cast<int>(p2);

	// reinterpret_cast purpose
	// int a = reinterpret_cast<int>(3.4);
}

