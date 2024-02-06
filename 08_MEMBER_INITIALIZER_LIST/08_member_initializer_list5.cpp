#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point() 			: x{0}, y{0}{} 
	Point(int a, int b) : x{a}, y{b}{} 
};

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
	// Rect()                                   
	Rect() : leftTop{0,0}, rightBottom{0,0}
	{
	}
};
class Rect2
{
	Point leftTop{0,0};
	Point rightBottom{0,0};
public:
	Rect2()                                   
	{
	}
};

int main()
{
	Rect rc; 
}
