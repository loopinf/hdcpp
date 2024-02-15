#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

void delay() { std::this_thread::sleep_for(20ms); }

std::mutex m;  //스레드간 동기화 도구

void foo(std::string_view name)
{
    // stack         : 스레드가 소유
    // static memory : process 가 소유
    // heap memory   : process 가 소유
    // GUI handle    : 스레드가 소유

    // int x = 0;    // 지역변수는 thread당 하나임
    //                 // 2개가 수행되면, 각각 사용

    static int x = 0; // 또는 전역변수, 모든 스레드가 한개 변수 공유

    for (int i = 0; i < 10; i++)
    {
        m.lock();
        // ------------------------------------
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
        // ------------------------------------
        m.unlock();
    }
}

int main()
{
    // 2개 스레드 내려가다가... m.lock 만남. 
    // 대기. 
    // 직렬화 라고 함
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



