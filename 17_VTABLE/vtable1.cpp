#include <iostream>

// 가상함수 원리   
// 149 page..

class Animal
{
	int age;
public: 
	virtual void cry() {}
	virtual void run() {}
};
//--------------------
class Dog : public Animal
{
	int color;
public:	
	void cry() override {}
};

int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d;
	p->cry();	
}


