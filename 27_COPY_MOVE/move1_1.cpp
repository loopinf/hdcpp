#include <iostream>
int main()
{
	int v = 0;
	v = 3; // ok
	3=v; //error
	const int c = 0;
	c = 3; // error 
			// c 는 lvalue (이름이 있음)
			// 바꿀수 없는 lvalue. immutable lvalue


	// lvalue , rvalue 구분법
	// lvalue : 이름이 있다. 사용자가 할당한 메모리, 단일식을 벗어나서 사용가능
	//			주소연산자로 주소를 구할 수 있다
	
	// rvalue : 이름이 없다. 임시로 만들어진 값.     단일식에서만 사용가능
	//			&3; // error
	//			&Point{1,2}; // error

	Point pt{1,2}; // 이름이 있다. lvalue
	Point{1,2};    // 이름이 없다. rvalue, 임시객체는 rvalue

}