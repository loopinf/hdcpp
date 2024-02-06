#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x{a}, y{b} {}

	void set(int a, int b) { x = a; y = b; }

	// const member function ; function () const 
		// 						 compiler this pointer is const pointer	
	// void print()    // void print(Point* this)
	void print() const     // void print( const Point* this)
	{	
		std::cout << x << ", " << y << std::endl;
	}
}; 
int main() 
{
	const Point p(1, 2); // const 객체

	p.set(10, 20);	 // set(&p, 10, 20)
	p.print();		 // print(&p)
					
}

