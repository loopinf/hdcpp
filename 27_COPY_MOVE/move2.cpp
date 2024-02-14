#include <iostream>

class vector 
{
public:
	vector(std::size_t size) {}
};

// 인자로
// foo(vector& v)      : lvalue만 전달 가능
// foo(const vector& v): lvalue, rvalue 모두 전달 가능
// foo(vector&& v)     : rvalue  만가능
// 
void foo(vector& v)         {std::cout << "1\n";} // lvalue 만 받을 수 있다.
void foo(const vector& v)   {std::cout << "2\n";} // lvalue rvalue ok
void foo(vector&& v) 		{std::cout << "3\n";} // lvalue rvalue ok


int main()
{
	vector v{10};

	foo(v); // lvalue, 1 호출, 없다면,2 호출
	foo(vector{10});  
			// rvalue
			// 3번호출, 만약 없다면, 2번호출
}
// lvalue 와 rvalue를 모두 받아서 같이 처리하고 싶다. 
// => 인자를 const lvalue& 로

// rvalue(임시객체)인 경우를 다르게 처리하고 싶다.
// => rvalue reference (vector&&) 버전 함수를 추가.