#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 스레드를 고려 하지 않은 함수
// => return 값으로 결과 반환
int add1(int a, int b)
{
	int s = a + b;
	return s;
}
// return 이 아닌 out parameter 사용
int add2(int a, int b, int& s)
{
	s = a + b;
}

int main()
{
	// 핵심 1. 스레드가 아닌 직접 호출은 함수의 결과를 반환값으로 받으면 됩니다.
	int ret1 = add1(1, 2);

	// 핵심 2. add1 을 스레드로 수행하면 결과를 받을 방법이 없음
	// std::thread t(&add1, 1, 2);

	// 핵심 3. out param 
	int s= 0;
	std::thread t1(&add2, 1,2, std::ref(s));

	t1.join();   // thread 의 종료를 기다림. 
					// 연산의 종료만 딱 기다리면 더 좋을 텐데

	std::cout << s << std::endl;


}
