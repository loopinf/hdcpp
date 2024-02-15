#include <iostream>
#include <thread>
#include <mutex>

constexpr unsigned int cnt = 1000000;


long x = 0; // 전역변수는 모든 스레드가 공유

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        x = x + 1;  
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
