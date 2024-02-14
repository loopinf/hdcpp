#include <iostream>
#include <memory>
#include <string>

struct People
{
    std::string name;

    People(std::string n) : name{n} {}
    ~People() { std::cout << name << " 파괴" << std::endl; }

    // std::shared_ptr<People> bf;  // shared_ptr 참조계수가 증가함
    People *bf; // raw pointer. 참조계수 증가는 안함
                // 객체는 잘 파괴되나, 문제가 있음. 다음에.
                // 단점: 가리키는 주소가 파괴되었는지 조사할 수 없다.
                // Dangling pointer 확률
                // smart pointer 의 목적: dangling pointer 제거
};

int main()
{
    std::shared_ptr<People> sp1{new People{"kim"}};
    {
        std::shared_ptr<People> sp2{new People{"lee"}};
        sp1->bf = sp2.get(); // 진짜 포인터.. smart pointer 말고,
        sp2->bf = sp1.get();
    }

    if (sp1->bf != nullptr)
    {
        auto name = sp1->bf->name;
    }
}
