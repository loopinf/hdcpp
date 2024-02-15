#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

class Machine
{
    int shared_data = 0;
public:
    void f1()
    {
        shared_data = 100;
    }
    void f2()
    {
        shared_data = 200;
    }
};
int main()
{
    Machine m;
    std::thread t1(&Machine::f1, &m);
    std::thread t2(&Machine::f2, &m);
    t1.join();
    t2.join();
}



