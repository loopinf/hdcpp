#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// 아래 코드가 핵심
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = nullptr) : obj(p) {}

	Car* operator->() { return obj; }
};
int main()
{
	// p 는 객체임. pointer아님
	// p 는 ptr 타입임. Car가 아님
	Ptr p = new Car; // Ptr p(new Car)
	// Ptr p;

	// Ptr의 객체인 p를 Car* 처럼 씀
	p->Go(); 
}


