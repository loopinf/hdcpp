#include <iostream>

// -------------------------------
// 가상함수 원리

// Animal 's all virtual function address, global array vtable

void * animal_vtable[] = { Animal type_info ,
                           &Animal::cry,
                           &Animal::run
                         }; 

class Animal
{
    void* vtptr = animal_vtable;
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
    // 1. complier p Animal* 
}


