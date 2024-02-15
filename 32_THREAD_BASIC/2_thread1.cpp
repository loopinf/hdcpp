#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
    foo(); // main thread 돌아감

    std::thread t(&foo);  // 새로운 thread 생성 후, foo를 실행해줘
                            // 즉시 생성후 실행
}

