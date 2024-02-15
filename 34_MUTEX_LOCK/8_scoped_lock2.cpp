// 1번 복사
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

struct Account
{
    std::mutex m;
    int money = 100;
};

void transfer(Account &acc1, Account &acc2, int cnt)
{
    // std::lock( acc1.m, acc2.m);
    // std::scoped_lock : 생성자에서 std::lock을 사용하는  lock관리 객체
    std::scoped_lock<std::mutex, std::mutex> sl(acc1.m, acc2.m);

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;

    // 예외 나오면 문제
    // acc1.m.unlock();
    // acc2.m.unlock();
}

int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}
