#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> up1(new int);     // ok
    std::unique_ptr<int> up2(new int[10]); //?? bug 할당은 array new, 소멸자는 array delete 사용안함

    // 해결책 #1. 함수객체 전달
    std::unique_ptr<int, ArrayDeleter> up2(new int[10]);

    // 해결책 #2. C++14부터 전달
    std::unique_ptr<int[]> up2(new int[10]);

    // shared_ptr 은 C++17 부터 [] 지원
    std::shared_ptr<int[]> sp2(new int[10]);
}