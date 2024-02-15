#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

void delay() { std::this_thread::sleep_for(20ms); }

void foo(std::string_view name)
{
    int x = 0;    // 지역변수는 thread당 하나임
                    // 2개가 수행되면, 각각 사용

    for (int i = 0; i < 10; i++)
    {
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
    }
}

int main()
{
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



