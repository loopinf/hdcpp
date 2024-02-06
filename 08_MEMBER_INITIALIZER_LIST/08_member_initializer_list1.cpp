#include <iostream>

class Point
{
	//  #1. field declared, not from constructor, literal 
	int x = 0; // good code
	int y{0};  // good code
public:
	// 멤버 데이타에 값을 넣는 3 방법
	
	// #0. constructor {} 안에서 대입
	// Point(int a, int b) 	// bad!!! don't use	
	// {
	// 	x = a; 
	// 	y = b;
	// }

	// #3. member initializer list 사용.
	Point(int a, int b) : x(a), y(b)  // Good .
	{
	}

};



int main()
{
	Point pt(0, 0);
}




