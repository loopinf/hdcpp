#include <thread>

int x = 0;
int y = 0;

// x, y 동시접근 못 막음 
// reordering 도 발생가능
void foo()
{
    int n1 = y;
    x = n1;
}
void goo()
{
    int n2 = x;
    y = 100;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}