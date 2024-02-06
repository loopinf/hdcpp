#include <iostream>

class Animal
{
public:
// non-virtual function: static binding
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
	// virtual : dynamic binding
	virtual void Cry2() { std::cout << "Animal Cry2" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	void Cry1() { std::cout << "Dog Cry1" << std::endl; }  // 2
	virtual void Cry2() { std::cout << "Dog Cry2" << std::endl; } // 2
};

int main()
{
	Animal a; 
	Dog    d; 

	Animal* p = &d;		

// if ( USER INPUT == 1 ) p = &a;
	p->Cry1(); // 1 ? 2    : 
				// call Animal::Cry1()
	p->Cry2(); // 1 ? 2    : 2
				// IF Dog call Dog::Cry2()
}

// p-> Cry1() what to call? function binding
// 1. static binding : compile time binding
//                     C++/C# : call 1, compiler knows the type of p, Animal* 

// 2. dynamic binding : runtime binding
// 						compile time , set a bit for dynamic binding
//                      runtime, check the bit 
//    			        Slow, 
//   C++/C# virtual function  
