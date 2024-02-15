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
}

