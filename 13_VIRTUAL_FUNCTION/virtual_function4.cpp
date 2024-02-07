#include <iostream>

// keypoint : base class destructor shoule be either
// 1. public virtual
// 2. protected non-virtual

// go to isocpp.org
class Base
{
public:
	Base() {}
	// ~Base() {  }
protected:
	~Base() {} //   base class destructor를 virtual로 만들어야 한다.-->
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { 
		std::cout << "~Derived() 자원해지" << std::endl; 
		// Base::~Base() --> compiler add 
		
		}
};

int main()
{
	Base* p = new Derived;
	// delete p;  // error protected destructor not accessible from main
	delete static_cast<Derived*>(p);
}
