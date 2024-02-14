#include <iostream>
// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. () 또는 {}로 초기화 가능, = 는 안됨
	std::shared_ptr<int> p1(new int);  // ok
	// std::shared_ptr<int> p1{new int};   // ok  
	std::shared_ptr<int> p2 = new int;  // error. explicit 생성자

	// 핵심 2. 스마트 포인터의 크기 : raw pointer size 의 2배
	std::cout << sizeof(p1)   << std::endl; // 일반 포인터의 2배. REF
	std::cout << sizeof(int*) << std::endl; // 32bit 환경 4, 64bit 환경에서는 8?

	// 핵심 3. -> 와 . 연산자
	// => 스마트포인터는 raw pointer 가 아닌 객체임.
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산과 . 연산이 모두가능
	// -> 연산 : 대상체(Car)의 멤버에 접근
	sp1->Go();
	// . 연산 : 대상체(Car) 가 아닌, shared_ptr 자체의 멤버에 접근
	int n = sp1.use_count(); // 참조계수 얻기, 현재는 2

	std::cout << n << std::endl;
	sp1.reset() ; //sp1 = nullptr 과 동일

}



