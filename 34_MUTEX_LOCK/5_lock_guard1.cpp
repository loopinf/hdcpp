#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;
//  C++ 격언 : 자원 반납은 함수 끝에서 하지마라
//              생성자 / 소멸자에 의존해라. RAII

void goo()
{
    m.lock();    
    std::cout << "using shared data" << std::endl;
    m.unlock();
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



