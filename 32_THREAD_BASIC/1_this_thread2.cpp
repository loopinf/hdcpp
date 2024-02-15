#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals; // 3s, 3ns 등을위해, user defined literal

int main()
{
    // #1. sleep_for : 특정시간동안 스레드 재우기
    // => 주의: 인자는 정수가 아님
    //          chrono type으로 해야
    // std::this_thread::sleep_for(3);
    std::this_thread::sleep_for(std::chrono::seconds{3});
    std::this_thread::sleep_for(3s);  // 3s : 3초객체
    std::this_thread::sleep_for(3ms); // 3s : 3초객체
    std::this_thread::sleep_for(3ns); // 3s : 3초객체

    3.4;  // double
    3.4f; // float
}
 std::this_thread::