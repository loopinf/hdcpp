#include <iostream>

// 139 page , 147 page
class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스에서 다시 구현하는 것
	// 
	// overloading 과 잘 구별 하세요 : square(int), square(double)

	void Cry1() { std::cout << "Dog Cry1" << std::endl; }  // 2
};

int main()
{
	Animal a; 
	Dog    d; 


	Animal* p = &d;		

	a.Cry1(); // 1
	d.Cry1(); // 2

	p->Cry1(); // 1 ? 2
				// C++/C# : call 1
				// Java, Python, Swift, kotlin, object-c : call 2 

}

