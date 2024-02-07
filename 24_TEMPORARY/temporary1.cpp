#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { std::cout << "Point()\n";}
	~Point()                         { std::cout << "~Point()\n";}
};

int main()
{
	Point pt(1, 1);    // named object
						// lifetime : block scope

	Point (1,2);        // unnamed object
						// lifetime : till the end of the statement
						// unnamed object is temporary object
						// class name... "prvalue" (pure rvalue)
						// temporary object is destroyed at the end of the statement

	Point {1,2};         // curly brace initialization
						// temporary object is destroyed at the end of the statement
						// better readablity

	std::cout << "-----------\n";

}