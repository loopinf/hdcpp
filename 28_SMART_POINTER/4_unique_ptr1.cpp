#include <iostream>

// shared_ptr 이 복잡했던 이유는
// => 한개의 객체를 "2개 이상의 스마트 포인터로 공유" 했기 때문..!

template <typename T>
class Ptr
{
	T *obj;

public:
	// explicit 생성자: 객체 생성시 = 로 초기화 할 수 없음. {} or () 로만 가능
	inline explicit (T *p = 0) : obj(p) {}
	inline T *operator->() { return obj; }
	inline T &operator*() { return *obj; }
	inline ~Ptr() { delete obj; }

	// 복사연산자 삭제시, 대입 연산자도 삭제함
	Ptr(const Ptr& other) = delete;
	Ptr& operator=(const Ptr& other) = delete;
};

int main()
{
	// Ptr<int> p1 = new int;
	// Ptr<int> p1(new int);
	Ptr<int> p1{new int};

	Ptr<int> p2 = p1; // 이렇게 사용하는 코드가 없다면, 참조계수(control block)
					  // 은 필요없다.
					  // 이렇게 사용하면 compile error 발생시킬것!
}
