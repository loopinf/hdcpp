#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int main()
{
	// vector , list, deque : sequence container


	// map : key 값으로 data 보관
	// python : dicitonarary
	std::map<std::string, std::string> m = { {"mon", "월요일"}, {"tue", "화요일"} };

	// 아래 처럼 넣어도 됩니다.
	m["wed"] = "수요일";

	std::cout << m["mon"] << std::endl; // 월요일
}





