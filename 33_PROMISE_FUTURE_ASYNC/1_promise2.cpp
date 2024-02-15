#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise & future 기술
// => thread 로 수행하는 함수에서 결과값을 얻을 때 사용

// 1. thread 함수는 "promise" 객체를 참조로 받아야함
int add(std::promise<int>& p, int a, int b)
{
	int s = a + b;
	// 2. 연산이 종료되면 p.set_value로 알려줌
	p.set_value(s);
}
int main()
{
	// thread 생성시
	// 1. thread 생성전에 promise 객체를 만들고, future를 꺼냄
	std::promise<int> p;
	std::future<int> ft = p.get_future();
	// 2. 스레드 생성할 때 promise를 참조로 전달
	std::thread t(&add, std::ref(p), 1,2);
}
