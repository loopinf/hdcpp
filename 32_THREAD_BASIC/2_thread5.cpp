#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id) {}

int main()
{
    // 핵심 1. 스레드를 만들면 반드시 join(), detach() 해야 합니다.
    std::thread t1(&do_work, 1);
    t1.join();

    // 핵심 2. 10개의 스레드를 생성해 봅시다.

	for( int i = 0; i < 10; i++)
	{
		
	}
}
