#include <string>
#include <iostream>
// Rule3. 사용자가 이동생성자만 만들때
// => 컴파일러는 복사생성자를 제공하지 않음. (삭제해?)
//    Person(const Person& ) = delete;

// => 복사 생성자가 필요한 코드를 사용하면 "compile error 남"
// => compiler 제공하는 복사 생성자가 필요하면, "=default"로 요청가능

struct Person
{
    std::string name;
    Person(const std::string &name) : name{name} {}
    // Person(const Person& other) : name{other.name}{
    //     std::cout << "Person copy\n";
    // }
    Person(Person&& other) : name { std::move(other.name)} {
        std::cout << "Person move\n";
    }
};

int main()
{
    Person p1{"kim"};
    Person p2{"lee"};

    Person p3 = p1;            // 사용자가 만든 복사생성자 사용
    Person p4 = std::move(p2); // 사용자가 만든 복사생성자 사용

    std::cout << p1.name << std::endl;
    std::cout << p2.name << std::endl;

}