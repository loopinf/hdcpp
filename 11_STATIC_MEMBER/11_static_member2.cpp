#include <iostream>

// 106page ~
// 객체가 몇개나 생성되었는지 갯수를 관리하고 싶다.
// 방법 2. global 변수 사용 => 

// global 

int cnt = 0;
class Car
{
	int color = 0;
public:	
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << cnt << std::endl;	
	
}
