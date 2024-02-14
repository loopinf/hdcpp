#include <iostream>

// noexcept 키워드의 2가지 용도
// 1. 함수가 예외가 있는지 조사
// 2. 함수가 예외가 없음을 컴파일러에게 알릴때 사용

void foo() 
{
}
// 함수가 예외가 없음을 알려주려면 () 뒤에 noexcept 를 표기해라.
void goo() noexcept   // 함수짠 사람이 확신할 때 쓰는 것. try catch 와는 상관없음
{
}

int main()
{
	// noexcept (함수호출표현식): 해당 함수가 예외가능성이 없으면 true, 있으면 false
	bool b1 = noexcept(foo());  // false, 모든 함수는 예외가능성이 있습니다.
								// 컴파일러는 함수 구현까지 조사하지 않고, 함수 선언만 보게 됩니다. 
	bool b2 = noexcept(goo());  // true, 
								//
	// why check noexcept?
	if ( noexcept(foo()))
	{
		// foo가 예외가 없다.
		// 안전하다
		foo(); // foo 사용
	}
	else{
		goo(); // 느리지만 안전한 다른 알고리즘
		// STL 내부에 위처럼 만들어진 부분이 많이 있음(move 배울때 자세히 설명)
	}
}