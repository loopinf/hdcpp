#include <string>
#include <iostream>
// Rule1. 
// => 컴파일러가 제공
// => 컴파일러가 제공 복사생성자는 모든 멤버를 복사해주고
// => 컴파일러가 제공하는 이동생성자는 모든 멤버를 이동해준다.(멤버의 이동생성자호출)

struct Person
{
    std::string name;
    Person(const std::string &name) : name{name} {}
};

int main()
{
    Person p1{"kim"};
    Person p2{"lee"};

    Person p3 = p1;
    Person p4 = std::move(p2);

    std::cout << p1.name << std::endl;
    std::cout << p2.name << std::endl;

}