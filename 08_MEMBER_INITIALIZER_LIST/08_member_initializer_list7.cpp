#include <iostream>

#include <iostream>

int g = 10;

class Test
{
	int v1 = ++g;
	int v2 = 0;
public:
	Test() {}               // : v1(++g), v2(0) 
	Test(int n) : v1(n) {}   //: v1(n), v2(0)
};

int main()
{
	Test t1;
	Test t2(5);
	std::cout << g << std::endl;	
}