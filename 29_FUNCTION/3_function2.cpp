#include <iostream>
#include <functional>
#include <vector>
using namespace std::placeholders;

// button 만들어졌다 치고, 누르면 a
class Button
{
	// void(*handler)();// 이렇게 만들면, 인자가 없는 non-member function만 등록가능
	// std::function<void()> handler;
	// std::vector<std::function<void()>> v;   // ok but 복잡해보임

	using HANDLER = std::function<void()>;
	std::vector<HANDLER>v ;

public:
	void add_handler(HANDLER h);
	void click()
	{
		// handler();
		for (auto f : v)
			f();
	}
};

int main()
{
	Button b1, b2;
	b1.click();		// 사용자가 버튼을 누를때 
}