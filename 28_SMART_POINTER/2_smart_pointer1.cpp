#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// 아래 코드가 핵심
// 개념: 임의차
// 원리: -> 와 * 연산자를 overloading 해서 포인터처럼 보이게 하는 것
// 장점: 객체 임, raw pointer가 아님
// 		생성/복사/대입/파괴의 모든 과정에서 각각 약속된 함수가 호출됨. 
//      추가적인 작업이 가능
// 		대표적인 활용: 소멸자에서 "자원 삭제(delete)" 기능
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = nullptr) : obj(p) {}
	~Ptr(){ delete obj; }

	Car* operator->() { return obj; }
	// Car operator*() { return *obj; }  // 값을 반환하면 *obj 를 복사한 임시객체 반환
	Car& operator*() { return *obj; }  // 임시객체 반환하지 말고, *obj 자체를 반환
};
int main()
{
	// p 는 객체임. pointer아님
	// p 는 ptr 타입임. Car가 아님
	Ptr p = new Car; // Ptr p(new Car)
	// Ptr p;

	// Ptr의 객체인 p를 Car* 처럼 씀
	p->Go(); 

	(*p).Go(); // 
}


