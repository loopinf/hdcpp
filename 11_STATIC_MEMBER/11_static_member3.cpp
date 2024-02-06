#include <iostream>

// 객체가 몇개나 생성되었는지 갯수를 관리하고 싶다.
// 방법 3. static member data

// global 

class Car
{
	int color = 0;
public:	
    // int cnt = 0;
    static int cnt;  // static 멤버 데이타
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int Car::cnt = 0; // static 멤버 데이타 초기화 ... outside of the class
// static member data 
// 1. 클래스 외부에 초기화가 반드시 필요하다.
// 2. 클래스 내부에서 초기화하면 안된다.
// 3. 클래스 내부에서 선언만 하고, 클래스 외부에서 초기화한다.
// 4. 클래스 외부에서 초기화할때는 클래스 이름을 사용해야 한다.
// 5. static 멤버 데이타는 객체가 없어도 메모리에 만들어진다.
// 6. static 멤버 데이타는 객체가 없어도 접근이 가능하다.
// 7. static 멤버 데이타는 객체가 없어도 생성자에서 초기화가 가능하다.
// 8. static 멤버 데이타는 객체가 없어도 소멸자에서 사용이 가능하다.
// 9. static 멤버 데이타는 객체가 없어도 사용이 가능하다.


int main()
{
	std::cout << Car::cnt << std::endl;	

	Car c1;
	Car c2;
	std::cout << c1.cnt << std::endl;	
	std::cout << c2.cnt << std::endl;	
	
}
