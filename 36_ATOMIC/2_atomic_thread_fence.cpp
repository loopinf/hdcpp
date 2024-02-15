#include <atomic>

// -O2 옵션이 있을때와 없을 때의 차이점 중요

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;
    b = 1;
}

// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ?
    }
}






