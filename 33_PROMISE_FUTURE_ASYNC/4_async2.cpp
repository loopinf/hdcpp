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
    // std::launch::async : 새로운 스레드로 수행
    // std::launch::deferred : 지연된 실행, ft.get()할때 main thread가 실행
	// std::future<int> ft = std::async(std::launch::async, &add, 1,2);
	// std::future<int> ft = std::async(std::launch::deferred, &add, 1,2);
 
    // launch option 생략시, std::launch::async | std::launch::deferred 
	std::future<int> ft = std::async(&add, 1,2);
	int ret = ft.get();
}
