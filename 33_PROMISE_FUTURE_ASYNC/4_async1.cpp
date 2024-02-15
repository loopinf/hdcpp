#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

// add : 결과를 return으로 반환
int add(int a, int b)
{
	std::this_thread::sleep_for(2s);
	return a + b;
}

int main()
{
	int r1 = add(1, 2); // 주스레드가 실행
	std::future<int> ft = std::async(&add, 1,2);
						// thread 로 실행후,future에 반환함

	// main thread 다른작업 하다가, 결과가 필요하면
	int ret = ft.get();
}


// std::async : "return 값" 형식의 함수를 즉시 스레드로 실행
//              내부적으로는 다시 std::thread 사용해서 생성
//              주로 "스레드 풀"로 구현
// 
// ==> 아래 방법은 모두 "std::thread" 사용
// packaged_task : "return 값" 으로 된 함수를 보관했다가 (promise 사용X)
//                  packaged_task 자체가 스레드 생성은 아님
//                 std::thread 로 실행해서 결과 얻기
//----------------------------------------
// promise / future : 결과를 얻기 위한 도구 (스레드 안만듬)
//----------------------------------------
// std::thread : C++에서 스레드를 만드는 클래스
//-----------------------------------------
// OS : CreateThread(), pthread_create()