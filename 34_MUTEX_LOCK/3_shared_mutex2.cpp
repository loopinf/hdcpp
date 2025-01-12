#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

// 1. 읽는 동안 쓸 수 없다.
// 2. 쓰는 동안 쓸 수 없다. 
// 3. 쓰는 동안 읽을 수 없다.

// 4. 읽는 동안 읽어도 된다!!

// std::mutex m;
std::shared_mutex m;
int share_data = 0; // buffer 라고 하자

// m.lock()        :다른 스레드의 lock, lock_shared() 모두 대기
// m.lock_shared() : 다른 스레드의 lock은 대기
//                  lock_shared 허용

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
        m.lock_shared();
        std::cout << "Reader(" << name << ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        m.unlock_shared();
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