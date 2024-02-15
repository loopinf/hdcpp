#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;
//  C++ 격언 : 자원 반납은 함수 끝에서 하지마라
//              생성자 / 소멸자에 의존해라. RAII


template<typename T>
struct lock_guard
{
    T& mtx;
    lock_guard(T& m) : mtx{m} {m.lock();}
    ~lock_guard()             {m.unlock();}
};

void goo()
{
    lock_guard<std::mutex> g(m); // 생성자에서 m.lock() 
                                    // 소멸자가 m.unlock()
                                    // 예외 발생해도 g의 소멸자 호출됨
    // m.lock();    
    std::cout << "using shared data" << std::endl;
    // throw 1;     
    // m.unlock();
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



