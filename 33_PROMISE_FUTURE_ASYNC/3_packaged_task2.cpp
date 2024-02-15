#include <iostream>
#include <thread>
#include <future>
// => 이미 아래 처럼 만들어진 함수를 스레드로 수행해서 결과 얻기

// 일반 함수라면 아래 처럼 만들게 됩니다.
int add(int a, int b)
{
	return a + b;
}

int main()
{
	// 1. 함수를 packaged_task 로 wrap 함
	std::packaged_task<int(int,int)> task(&add);
	// 2. task 에서 future 꺼내기
	std::future<int> ft = task.get_future();

	// 3. 이제 task실행
	// task(1,2) ;  // main thread 만 허용함.
	std::thread t(std::ref(task), 1, 2);

	// int ret = ft.get(); 결과 대기

	


}


// promise & future : 함수인자로 promise 를 받아야 합니다
// 
// packaged_task    : 스레드 함수가 아닌 일반 함수 모양으로
//						만들어진 함수를 스레드로 수행해서 결과 얻기
//						"보관" 했다가 "원할때 실행"


