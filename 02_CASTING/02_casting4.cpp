#include <iostream>

// static_cast : 논리적으로 맞고 위험하지 않은 경우만 허용
//          1. void*=> 다른 타입*,
//			2. 상속관계의 캐스팅 등.
//          3. 반드시 연관성이 있어야 한다

int main()
{
	double d = 3.4;

	// #1. 표준 타입 끼리의 변환
	// int    n = d; // compile possible, warning
	int    n = static_cast<int>(d); // ok. remove warning

	// #2. void* => 다른타입* 변환
	// C lang : casting not needed
	// c++ lang: casting 
	// int* p1 = malloc(100);    
	int* p1 = static_cast<int*>(malloc(100));
								// TODO "void* => differenct *" cast ? when needed?

	// #3. int* => double* 
	// double* p2 = &n; // error
	// double* p2 = static_cast<double*>(&n); // error, danger!!
	double* p2 = reinterpret_cast<double*>(&n); // error, 
												// intended, known danger!!


}

