#include <iostream>

class Point
{
	int x, y;
public:
	void set(int a, int b)	 // void set(Point* this, int a, int b)
	{						
		x = a;				// this->x = a;
		y = b;				// this->y = b;
		std::cout << "set this : " << this << std::endl;
	}
	/*// this : 
	void set_23ver(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
	*/
};

int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;

	p1.set(10, 20);  // set(&p1, 10, 20);
	p2.set(10, 20);  // set(&p2, 10, 20);
}
