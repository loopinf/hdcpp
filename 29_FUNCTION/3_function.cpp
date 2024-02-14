#include <iostream>
#include <functional>

void f1(int a) {}
void f2(int a, int b) {}

struct Dialog 
{	
	void close(int code) {} 
};

int main()
{
	void(*f)(int); 
	f = &f1;
	f = &f2;

	
}