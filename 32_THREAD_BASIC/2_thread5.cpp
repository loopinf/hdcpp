#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id) {}

int main()
{
    // 핵심 1. 스레드를 만들면 반드시 join(), detach() 해야 합니다.
    // => "t1" 이라는 객체의 이름을 알고 있어야 함
    std::thread t1(&do_work, 1);
    t1.join();

    // 핵심 2. 10개의 스레드를 생성해 봅시다.
    std::vector<std::thread> v(10); // thread obj 10 created
                                    // thread 는 생성안됨
    for (int i = 0; i < 10; i++)
    {
        v[i] = std::thread(&do_work, i);
    }
    // for (auto e : v)  // thread 객체를 복사하는 것임. ERROR
    for (auto &e : v)
        e.join();
}
