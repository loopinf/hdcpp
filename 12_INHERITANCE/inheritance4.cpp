#include <iostream>

// 핵심 : 기반 클래스인 Base 에 디폴트 생성자가 없습니다.
// => 아래 코드에서 에러를 모두 찾아 보세요. 

class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// Derived()      {}   // Derived() : Base()  => error
	// Derived(int a) {}   // Derived(int a) : Base()  => error
	
	// if no default constructor in Base, you must call Base(int) in Derived
	Derived() 	   : Base(0){}
	Derived(int a) : Base(a) {}
};

int main()
{
}




