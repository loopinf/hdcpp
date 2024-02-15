#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::mutex m;
int share_data = 0;

void foo()
{
    m.lock();
    share_data = 100;
    std::cout << "using share_data" << std::endl;
    m.unlock();
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




