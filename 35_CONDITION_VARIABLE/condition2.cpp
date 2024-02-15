#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;
// 1. 헤더파일
#include <condition_variable>

std::mutex m;
int shared_data = -1; // 아직 데이터 없음

// 2. 전역변수 생성
std::condition_variable cv;



void consumer()
{
    // 3. 소비자는 unique_lock으로 mutex 획득
    // std::lock_guard<std::mutex> lg(m);
    std::unique_lock<std::mutex> u(m);

    // 4. 신호가 올때까지 대기
    cv.wait(u); // 1. u.unlock() 으로  lock을 풀고
                // 2. cv의 신호를 대기
                // 3. 신호가 오면 다시, u.lock() 하고
                // 4. 아랫줄 실행


    std::cout << "consume : " << shared_data << std::endl;
}
// 생산자, 쓰기 전용
void producer()
{
    std::this_thread::sleep_for(10ms);
    std::lock_guard<std::mutex> lg(m);
    shared_data = 100;
    std::cout << "produce : " << shared_data << std::endl;
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); 
    t2.join();
}