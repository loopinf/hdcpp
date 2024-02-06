// 5_생성자1.cpp
#include <iostream>
#include <string>

class Person
{
// public:
private:
	std::string name;
	int  age;
public:
	void init(const std::string& s, int a)
	{
		name = s;
		age = a;
	}

//   생성자(constructor)
	Person(const std::string& s, int a)
	{
		name = s;
		age = a;
	}

};

int main()
{
	// #1. 멤버 데이타가 모두 public 에 있다면 아래 처럼 초기화 가능합니다.
	// => struct 와 동일
	// Person p = { "kim", 28 }; 
	// Person p;
	// p.init("kim", 28);

	// #3. 생성자를 이용해서 초기화
	Person p("kim", 28); // 생성자 호출


}


