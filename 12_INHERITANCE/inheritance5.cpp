#include <iostream>
#include <vector>
using namespace std;

class People
{
	std::string name;
	int age;

public:
	// All member variables need to be initialized with
	People(const std::string &n, int a) : name{n}, age{a} {}
};

// People <-- Student
// => Add int id to People
// => Add Student constructor
// => Add Student object in main
class Student : public People
{
	int id;

public:
	Student(const std::string &name, int age, int id) : People{name, age},
														id{id}
	{
		cout << "Student(const std::string &n, int a, int i)" << endl;
	}
};

int main()
{
	People p{"kim", 20};	 // 이렇게 객체를 만들수 있게 하면 좋을까요 ?
							 // 이름과 나이가 초기화 되지 않은 쓰레기값을 가지는 객체
	Student s{"lee", 22, 1}; // 이렇게 객체를 만들수 있게 하면 좋을까요 ?
							 // 이름과 나이가 초기화 되지 않은 쓰레기값을 가지는 객체
}
