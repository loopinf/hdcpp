// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:	int age;
};
class Dog : public Animal
{
public:	int color;
};
class Cat : public Animal
{
public:	int speed;
};
void NewYear( Animal* p )
{
	++(p->age);
}

int main()
{
	// Upcasting 활용/장점
	// std::vector<Dog*> v1; // ?// 6_Upcasting1.cpp      140 page ~
	Dog* woori[10];  // Dog only array
	Animal* woori[10]; // Animal array
}