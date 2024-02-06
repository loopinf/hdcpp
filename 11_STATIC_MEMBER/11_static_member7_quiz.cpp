#include <iostream>
class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요
	// 1. static member data
	void foo()	
	{
		color = 0;	// 1. 
		cnt = 0;	// 2. 
		goo();		// 3. 

		std::cout << this; // 4.
	}
	static void goo()	
	{
		color = 0;	// 5. 
		cnt = 0;	// 6. 
		foo();		// 7. 

		std::cout << this; // 8.
	}
};
int Car::cnt;

int main()
{
	Car::goo();  // static 

	Car c;
	c.foo();	// non-static
	c.goo();	// Car::goo();
}

// Summary
// 1. static member function은 static member (data, function) 만 접근 가능하다.
