
// 4_접근지정자1 - 74page
#include <iostream>
#include <string>

//  encapsulation
// 1. data hiding : private
// 2. member function : public
// 3. member function : access private member

// struct Person
class Person
{
// private:     // only member function can access private member
// default public on struct
	std::string name;
	int  age;	
public:
	void set_age(int a)
	{
		if (a > 1 && a < 150){
			age = a;
		}
	}
};

int main()
{
	Person p;
	// p.name = "kim";
	// p.age = -10; // 사용자가 실수 했다.				 
	p.set_age(-10); // 
}