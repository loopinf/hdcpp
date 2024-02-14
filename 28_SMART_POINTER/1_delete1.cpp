#include <iostream>

int main()
{
	// C/C++, 메모리 할당하면 반드시 delete 해라., 배열은 배열로 지워라.
	int* p1 = new int;	
	delete p1;

	int* p2 = new int[10];	
	delete[] p2;
	// delete p2;  // bug, undefined

}