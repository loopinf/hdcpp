#include <iostream>

// this 활용

class Point
{
	int x, y;

public:
	// #1.
	void set(int x, int y)
	{
		x = x;		 //  left
		this->x = x; // this->x = x;

		std::cout << this
	}

	// #2. this 를 반환
	Point *foo() { return this; }
	Point& goo() { return *this; }
};
int main()
{
	Point p1;
	p1.set(10, 20);

	p1.foo()->foo();
	p1.goo().goo().goo();
}
