#include <iostream>
#include <memory>

/*
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}
*/
struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	// std::shared_ptr<Point> sp(new Point(1, 2));
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2); // memory concat..
								// 1. sizeof(Point) + sizeof(control_block)할당
								// 2. Point memory (1,2) 로 초기화
								// 3. 해당 메모리를 관리하는 shared_ptr만들어서 반환
								
	// std::make_shared 의 장점
	// 1. memory managed efficiently
	// 2. safety 

	// 아래 코드는 : (2)-(1)-(3) 순서대로 실행되면 안전!
	//				(2)-(3)-(1) 순서대로 실행되고, (3)인 goo()에서 예외가 발생하면
	// 							메모리 누수
	foo( std::shared_ptr<int>(new int), goo());
	//              (1)          (2)     (3)
	// 핵심: 자원 할당과, 자원관리객체의 생성은 한번에 해야함.
				// std::make_shared의 철학

	foo( std::make_shared<int>(0),  // "메모리할당 + shared_ptr"생성, 0은 초기값
		goo());


	
	
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

