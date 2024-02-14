#include <iostream>
#include <memory>
#include <string>

struct People
{
	std::string name;

	People(std::string n) : name{n} {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf;
};

int main()
{
	// std::make_shared 가 좋지만, 설명을 위해서 new People
	std::shared_ptr<People> sp1{new People{"kim"}};
	std::shared_ptr<People> sp2{new People{"lee"}};

	// 아래코드, 메모리 누수 (p204 diagram)
	// 상호참조, 원형 참조(cycle reference) 발생
	sp1->bf = sp2;
	sp2->bf = sp1;

}


