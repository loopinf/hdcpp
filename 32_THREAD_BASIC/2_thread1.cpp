#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
    // foo(); // main thread 돌아감

    std::thread t(&foo);  // 새로운 thread 생성 후, foo를 실행해줘
                            // 즉시 생성후 실행
    // #2. thread 생성한 경우, 반드시 "detach" 또는 " join"  필요
    // t.join();  // 스레드 종료시가지 main thread 대기
    t.detach();  // 새로운 Thread 와 관계를 끊는 것
                    // t가 내부적으로 관리하는 핸들 닫기
                    // main thread 와 분리되어 실행됨

    std::cout << "main continue\n";
    // #. join하지 않는 경우
    // => main thread 종료되면, 프로세스내의 모든 thread 강제종료됨

}

