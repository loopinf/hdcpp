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
	Point from{10, 10};
	Point to{20, 20};

	draw_line(from, to);
}