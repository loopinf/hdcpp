#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

//======================================================
void draw_line(const Point& from, const Point& to) {}

int main()
{
	// draw a line from (10,10) to (20,20)

	// 1. make a variable(object) and pass as argument
	Point from{10, 10};
	Point to{20, 20};

	draw_line(from, to);
	// 2. create a temporary object
	draw_line(Point{10, 10}, Point{20, 20});  // used as argument -> temporary object is better
										// temporary object is destroyed at the end of the statement



}