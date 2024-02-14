#include <string>
#include <iostream>
#include <string.h>
// Rule1. 
// => 컴파일러가 제공
// => 컴파일러가 제공 복사생성자는 모든 멤버를 복사해주고
// => 컴파일러가 제공하는 이동생성자는 모든 멤버를 이동해준다.(멤버의 이동생성자호출)

// struct Person
// {
//     Person(const char* n){
//         name = new char[strlen(n)];
//         memcpy(name, n, sizeof(char)*strlen(n));
//     }
//     // 위처럼 생성자에서 사용자가 직접 자원 할당하면
//     // 1. 소멸자도 만들어야
//     // 2. 복사 생성자도 필요
//     // 3. move 지원하려면, move생성자도 필요함
//     // => 모두
// };
// 
struct Person{
    std::string name;
    Person(const std::string& name) : name{name}{}
};
int main()
{
}
// special member functions
// => 사용자가 만들지 않으면 컴파일러가 제공하는 것들
// 1. 생성자를 한개도 만들지 않으면 "Default constructor"
// 2. 소멸자 만들지 않으면, 소멸자 제공
// 3. 복사생성자 제공
// 4. 대입 연산자 제공
// 5. 이동 생성자
// 6. 이동대입 연산자.

Point p1;
Point p2 = p1; // 복사 생성자
p2 = p1; // 대입 생성자

Point p3 = std::move(p1);// 이동생성자
p3 = std::move(p2); // 이동 대입 연산자

// C++
// 복사보다 이동이 빠르다 //but default 가 복사임. 필요할 때 move함. 
// std::string s2 = s1; // 복사
auto s2 = s1; // 복사
auto s3 = std::move(s1); // 이동

// Rust : default 가 이동, 복사가 필요하면, .Clone() 호출 
let s2 = s1; // 이동
let s3 = s1.Clone() // 복사