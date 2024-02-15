#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;


int share_data = 0;

void foo()
{
    share_data = 100;
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}



