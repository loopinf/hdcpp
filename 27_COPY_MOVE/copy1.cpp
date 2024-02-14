#include <iostream>

class Point 
{
public:	
	int x, y;

	Point() 			: x{0}, y{0} {}
	Point(int x, int y) : x{x}, y{y} {}
};

int main()
{
	Point p1;
	Point p2{1, 1};
	Point p3{1};
	Point p4{p2};

	std::cout << p4.x << ", " << p4.y << std::endl;
}