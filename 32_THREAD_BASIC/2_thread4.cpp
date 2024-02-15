#include <thread>

// copy, move

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

	// #1. swap

	// #2. copy, move

	// #3. thread 객체를 먼저 만들고, 나중에 실행


    t2.join();
    t4.join();
}

