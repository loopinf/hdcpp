#include <iostream>
#include <thread>

// 스레드 함수의 모양
void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};
struct Work
{
    void operator()(int a, double b) const {}
};

int main()
{
    std::thread t1(&foo, 1, 3.4);

    Machine m;
    std::thread t2(&Machine::Run, &m, 1, 3.4);

    Work w;
    std::thread t3(w, 1, 3.4); //주의 &w가 아닌 w
                                // w(1,3.4) 를 thread로

    t1.join();
    t2.join();
    t3.join();

}

