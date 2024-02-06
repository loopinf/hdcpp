#include <iostream>
class Car
{
	int color = 0;
    static int cnt;  // static 멤버 데이타
public:	
    Car() { ++cnt; }
    ~Car() { --cnt; }
    // int get_count() const { return cnt; }
    //                         // => normal member function
    //                         // object.function()
    static int get_count()  { return cnt; }
                            // => static member function
                            // class::function()
                            // object.function()
};

int Car::cnt = 0; // static 멤버 데이타 초기화 ... outside of the class
// Car::cnt = 100; // error 

int main()
{
	// std::cout << Car::cnt << std::endl;	
    // 1. Car::cnt 

	std::cout << Car::get_count() << std::endl;	
	Car c1;
	Car c2;
	std::cout << c2.get_count() << std::endl;	// bad
	std::cout << Car::get_count() << std::endl;	// good
	
}
// summary
// static member variable : global variable,  class variable

// static member function : possible to call without object
//                          access to Car, private 