#include <iostream>
#include <string>
#include <thread>

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

     // 인자 전달 방법
     std::thread t1(&f1); // 인자없는 함수 스레드로 실행
     std::thread t2(&f2, 1, 3.4); // 스레드함수에 인자 전달

     std::thread t3(&f3, 1, std::ref(n), // n을 reference로 보내라. but ref 보내는 건 위험한 코드임. 
                    std::move(s));
     t1.join();
     t2.join();
     t3.join();
}

