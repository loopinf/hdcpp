#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	int  age;
public:
	// 핵심 1. class 생성자는 여러개 만들수 있다.
	// keypoint : same with class name  
	Person(const std::string& n, int a)
	{
		std::cout << "생성자1 호출됨" << std::endl;
		name = n;
		age = a;
	}	

	Person()
	{
		std::cout << "생성자2 호출됨" << std::endl;
		name = "unknown";
		age = 0;
	}

	// 소멸자 : "~클래스이름" 모양의 함수
	//			반환값과 인자가 없다. 오직 한개만 만들수 있다.
	//		    객체가 파괴 될때 호출.
	~Person() { std::cout << "소멸자" << std::endl; }
};

int main()
{
	Person p1("kim", 28); // 생성자1 호출
	Person p2;			  // 생성자2 호출

} 
