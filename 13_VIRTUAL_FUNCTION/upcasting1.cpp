#include <vector>

// 135 page ~

class Animal
{
public:	
	int age;
};
class Dog : public Animal
{
public:	
	int color;
};
int main()
{
	Dog     dog;

	Dog*    p1 = &dog;	// ?

	// int*    p2 = &dog;	// error. type wrong
	
	Animal* p3 = &dog;	// upcasting .. very important!!!

	// upcasting pointer
	// C++ : p3 type is Animal* but it points to Dog object
	//		 static type check : compile time type check
	// python : dynamic type check, 
	p3->age = 3;		// ok
	p3->color = 2;	// error. type wrong

	static_cast<Dog*>(p3)->color = 2;	// ok, but not good be sure it is Dog object
	((Dog*)p3)->color = 2;	// ok
	// 
	((Dog*)p3)->color = 2;	// ok



}




