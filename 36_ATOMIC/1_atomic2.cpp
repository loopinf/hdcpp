#include <iostream>
#include <thread>
#include <atomic>

long x = 0;
std::atomic<long> x = 0; // 전역변수이지만
                        // 멀티쓰레드에 안전한 코드

void foo()
{
    for (int i = 0; i < 100000; ++i)
    {
        ++x; 
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
