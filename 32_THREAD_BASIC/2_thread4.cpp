#include <thread>

// copy, move

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

	// #1. swap
    t1.swap(t2); // thread 교환

	// #2. copy, move
    // => 복사 불가, 이동 가능
    std::thread t3 = t1; // error 
    std::thread t4 = std::move(t1); // ok. 

	// #3. thread 객체를 먼저 만들고, 나중에 실행
    std::thread t5; // 아직 thread 생성되지 않음, 관리객체만 생성

    t5 = std::thread(&foo); // thread 만들어서 t5와 연결
                        // 임시객체 생성, rvalue
                        // 따라서, 복사대입이 아닌, "이동 대입연산자" 호출

    // 뭐하러? 나중에 여러 thread 연결할려고...


    t2.join();
    t4.join();
}

