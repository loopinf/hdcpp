#include <iostream>

// 1. 스마트포인터는 템플릿으로 만들어야 함
// 2. 사용자가 복사생성자를 만들어서 얕은 복사 문제를 해결해야함

template <typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = nullptr) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }  // 임시객체 반환하지 말고, *obj 자체를 반환
	~Ptr(){ delete obj; }
};

int main()
{
    Ptr<int> p1 = new int;
    *p1 = 20;

    Ptr<int> p2 = p1; // 이렇게 사용하면 runtime error. 얕은 복사

}


