#include <iostream>

int main()
{
	int* p1 = new int;	
	delete p1;

	int* p2 = new int[10];	
	delete[] p2;

}