#include <iostream>

class Point
{
public:
	int x, y;
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

//======================================================
//  ARM: annotated reference manual
void draw_line(const Point& from, const Point& to) {}

void reset( Point& p) { p.x = 0; p.y = 0; }
int main()
{
	reset( Point{10, 10} );  
					// error: 
					// cannot bind non-const lvalue reference of type 'Point&' to an rvalue of type 'Point'
	draw_line(Point{10, 10}, Point{20, 20});  // used as argument -> temporary object is better
	// temporary object and reference
	Point&r = Point{10, 10}; // error
	const Point& cr = Point{10, 10}; // ok
									// temp. object lifetime is cr lifetime
									// life-time extension rule
}