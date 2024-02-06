#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x{a}, y{b} {}

	void set(int a, int b) { x = a; y = b; }

	void print()
	{	
		std::cout << x << ", " << y << std::endl;
	}
}; 
int main() 
{
	// Point p(1, 2);
	const Point p(1, 2); // const 객체

	p.x = 10;		 // error. x  public but p is const object
	p.set(10, 20);	// error
	p.print();		// error why? 
					// c	
}

