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
			f(); // f는 결국 std::function 이므로, ()로 호출가능 
	}
};
// ------
void f0() {std::cout<< "f0\n";}
void f1(int a) {}

class Dialog 
{
public:
	void close(int code) {}  // void close(Dialog* this, int code)
};


int main()
{
	Button b1 ;
	b1.add_handler(&f0);
	b1.add_handler(std::bind(&f1, 11));  // 11을 버튼id라고 생각하면 됨
	Dialog dlg;
	b1.add_handler(std::bind(&Dialog::close, &dlg, 1));

	b1.add_handler( [](){std::cout<<"lambda\n"});

	b1.click();

}
// C++26에서 network 라이브러리가 표준에 추가된 예정
// => boost 라이브러리는 asio 를 약간 수정해서 추가 예정
// => asio 코드는 대부분 std::bind 와 std::function으로 작업