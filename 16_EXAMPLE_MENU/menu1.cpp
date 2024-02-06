#include <iostream>
#include <string>
#include <vector>
// #include <conio.h>  // not supported in Linux

// 객체지향 프로그래밍의 핵심
// => Everything is an object
// => 프로그램에서 필요한 타입을 먼저 설계해라!

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) 
		: title{title}, id{id} {}
	std::string get_title() const { return title; }
	void command() {
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		getchar();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴를 선택하면 호출할 함수!
}
