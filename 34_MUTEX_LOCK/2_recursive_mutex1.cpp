#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// std::mutex m;
std::recursive_mutex m;
int share_data = 0;

void foo()
{
    m.lock();
    m.lock();  // 소유자가 한번더?? lock 안됨.
                // recursive 는 됨.
    share_data = 100;
    std::cout << "using share_data" << std::endl;
    m.unlock();
    m.unlock();  // 두번 풀어야함
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




