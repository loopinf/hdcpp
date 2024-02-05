// 9_초기화리스트1-1
#include <string>

int main()
{
	// 초기화 : 선언하면서 값을 넣는 것
	// 대입   : 선언후에 값을 넣는것
	
	int a = 10;	// 초기화(initialization)

	int b;
	b = 10;		// 대입(assignment)


	//========================================================
	// std::string : class 문법으로 만들어져 있는 타입입니다.(STL)

	std::string s1("hello");	// 초기화. string(const char*) 버전의 생성자 호출
								// 즉, 함수 호출이 한번으로 객체가 초기화 된것. 

	std::string s2;	// 1. 인자 없는 생성자(디폴트 생성자) 호출
	s2 = "hello";	// 2. 대입연산자라는 함수 호출 ( s2.operator=("hello") )
					// 즉, 2번의 호출로 값을 넣은것


	// 핵심 : user define type 은 항상, 대입 보다 초기화로 값을 넣는것이 좋습니다.

}