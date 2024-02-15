#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::mutex m;
int share_data = 0;

void foo()
{
    // m.lock();
    if (m.try_lock()) // 뮤텍스 획득못했으면, 딴일해..
    {
        share_data = 100;
        m.unlock();
    }
    else
    {

    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    // 늦게 도착한 넘은 대기!
    // mutex 획득 못한 경우, 대기상태

    t1.join();
    t2.join();
}
