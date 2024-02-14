#include <iostream>

// class 안에 포인터멤버가 없다면
// => 컴파일러가 제공한 복사생성자를 사용해도 됨

// 포인터멤버가 있다면
// => 컴파일러가 제공한 복사생성자는 얕은 복사(shallow copy)
			// 주소만 복사함. 
// => 반드시 복사생성자를 사용자가 만들어서 문제를 해결!!
class vector 
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new int[sz];
	}
	~vector() { delete[] ptr; }
};
int main()
{
	vector v1{10};  // 메모리 모양 생각해보세요.
	vector v2 = v1; // 현재 이코드때문에 runtime error
					// vector v2{v1} 거의 동일 (약간의 차이 있음)
					// 컴파일러가 제공하는 복사 생성자를 사용
					// 동일한 메모리 두번 지우면, undefined. 디버깅 모드에서는 죽음
}