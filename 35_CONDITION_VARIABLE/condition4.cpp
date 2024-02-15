

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;
// 1. 헤더파일
#include <condition_variable>

std::mutex m;
int shared_data = -1; // 아직 데이터 없음

// conditional_variable은 관례상 전역변수와 같이 사용됨
std::condition_variable cv;
bool data_ready = false;

void consumer()
{
    std::unique_lock<std::mutex> u(m);

    // 4. 신호가 올때까지 대기
    cv.wait(u); // 무조건 신호를 대기
    cv.wait(u, 함수); // 함수를 실행해서 결과가 참이면 대기 안함

    cv.wait(u, []() { return data_ready == true;});
    // 1. 함수를 실행해서 결과가 참이면 대기안함
    // 2. 거짓이면 unlock 후 신호가 올때까지 대기
    // 3. 신호가 오면 깨어나면 1번으로 이동

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
    std::this_thread::sleep_for(10ms);
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;
    }
    data_ready = true;
    cv.notify_one();

}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}