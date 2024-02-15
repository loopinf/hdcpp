#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

std::mutex m;
int share_data = 0; // buffer 라고 하자

void Writer()
{
    while (1)
    {
        m.lock();
        share_data = share_data + 1;
        std::cout << "Writer : " << share_data << std::endl;
        std::this_thread::sleep_for(1s);
        m.unlock();
        std::this_thread::sleep_for(10ms);
    }
}
void Reader(std::string_view name)
{
    while (1)
    {
        m.lock();
        std::cout << "Reader(" << name << ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        m.unlock();
        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");  // 읽는 동안에 다른애들도 읽을 수 있어야 함.
    std::thread t4(Reader, "C");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}