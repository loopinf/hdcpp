#include <iostream>

class Base
{
public:
	Base()  {  }
	// ~Base() {  }
	virtual ~Base() {  }  //   base class destructor를 virtual로 만들어야 한다.-->
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};

int main()
{
	// Derived d;	

	// Derived* p = new Derived;	
	// delete p;		
	Base* p = new Derived;
	delete p;
}





