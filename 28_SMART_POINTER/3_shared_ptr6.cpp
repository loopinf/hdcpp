#include <iostream>
#include <memory>
#include <string>

struct People
{
    std::string name;

    People(std::string n) : name{n} {}
    ~People() { std::cout << name << " 파괴" << std::endl; }

    // std::shared_ptr<People> bf;  // shared_ptr 참조계수가 증가함
    // People *bf; // raw pointer. 참조계수 증가는 안함
    std::weak_ptr<People> bf;  // 1. 참조계수가 증가하지 않는 스마트포인터
                                //2. 자신이 가리키는 곳이 파괴되었는지 조사 가능

};

int main()
{
    std::shared_ptr<People> sp1{new People{"kim"}};
    {
        std::shared_ptr<People> sp2{new People{"lee"}};
        // sp1->bf = sp2.get(); // 진짜 포인터.. smart pointer 말고,
        // sp2->bf = sp1.get();
        sp1->bf = sp2;
        sp2->bf = sp1;
    }

    if (sp1->bf.expired())
    {
        std::cout<< "sp1->bf 파괴\n";
    }
    else{
        std::cout << "sp1->bf 파괴안됨\n";;
        // 아직 파괴 안되었으니, 객체 접근
        // auto name = sp1->bf->name; // error
        // auto name = sp1->bf->name; // error
        // shared_ptr : 참조계수 증가, 객체에 대한 소유권이 있다.
        //              겍체에 접근해도 항상 안전하다
        // weak_ptr   : 참조계수 증가 안됨. 객체에 대한 소유권이 없다.
        //              객체에 접근해서 사용중일떄, 객체는 파괴될 수도 있다.
        //              객체에 접근하지 못하게 하기 위해 -> 연산자 제공안함

        // weak_ptr 로 객체 접근하려면, shared_ptr을 다시 만들어야 함.
        std::shared_ptr<People> sp = sp1->bf.lock();

        if (sp)
        {
            auto name = sp->name;
        }


    }
}
