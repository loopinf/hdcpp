#include <string>
#include <iostream>
// Rule2. Only make copy ctor

// => compiler 는 이동생성자 안만들어줌.
// =? 이동생성자가 필요한 코드 사용하면(std::move(p1) 처럼럼
// 

struct Person
{
    std::string name;
    Person(const std::string &name) : name{name} {}
    Person(const Person& other) : name{other.name}{
        std::cout << "Person copy\n";
    }
    // 아래 처럼하면, 이동생성자의 디폴트버전 요청 가능함
    Person(Person&&) = default;
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