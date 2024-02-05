// 45page ~
#include <iostream>
using namespace std;
int main()
{
	int n = 0x11223344;

	// int 변수의 주소를 char* 에 담는 이유
	// => 메모리를 접근하는 방법을 변경하겠다는 의도
	// => 4바이트 메모리를 1바이트 단위로 접근 하겠다는 것
	// char* p1 = &n; // ?? error
	char* p1 = (char *)&n;  // ok... c style () casting


	if ( *p1 == 0x44 ) { cout << 'test' << endl;}

	// ===============================================
	// c lang, () casting 
	double* p2 = (double*)&n;
	*p2 = 3.4;


	// double* p2 = &n; // ??
}
