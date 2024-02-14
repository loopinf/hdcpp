#include <iostream>

class Point 
{
public:	
	int x, y;

	Point() 			: x{0}, y{0} {}
	Point(int x, int y) : x{x}, y{y} {}
	// 복사 생성자 : 자신과 동일한 타입의 객체를 인자로 한개 받는 생성자
	//				사용자가 만들지 않으면, 컴파일러가 만듬
	// 아래 모양이 컴파일러가 제공하는 모양
	// => all members are shallow copied (얕은 복사)
	// Point(const Point& other) :x{other.x}, y{other.y} {}
};

int main()
{
	Point p1;            // 1번 생성자 호출
	Point p2{1, 1};      // 2번 생성자 호출
	// Point p3{1};         // compile error. 
	Point p4{p2};         // OK. copy constructor Point(Point) 모양의 constructor needed
						// compiler generates

	std::cout << p4.x << ", " << p4.y << std::endl;
}