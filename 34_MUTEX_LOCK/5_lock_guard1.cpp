#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;
//  C++ 격언 : 자원 반납은 함수 끝에서 하지마라
//              생성자 / 소멸자에 의존해라. RAII

template <typename T>
struct lock_guard
{
    T &mtx;
    lock_guard(T &m) : mtx{m} { m.lock(); }
    lock_guard(T &m, int n) : mtx{m} {}
    ~lock_guard() { m.unlock(); }
};

void goo()
{
    // lock_guard<std::mutex> g(m);
    if (m.try_lock())
    {
        // lock은 다른 방법으로 했지만, unlock은 lock_guard로 하고 싶다.
        // m.unlock();
        lock_guard<std::mutex> g(m);
    }
}

void foo()
{
    goo();
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}
