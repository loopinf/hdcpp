#include <iostream>

// shared_ptr 이 복잡했던 이유는
// => 한개의 객체를 "2개 이상의 스마트 포인터로 공유" 했기 때문..!

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() { delete obj; }
};

int main()
{
	Ptr<int> p1 = new int;

	Ptr<int> p2 = p1; //
}


