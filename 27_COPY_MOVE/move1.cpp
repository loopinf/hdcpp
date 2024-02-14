#include <iostream>

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

	vector(const vector& other) : sz{ other.sz} 
	{
		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);
	}
};
int main()
{
	vector v1{10};
	vector v2 = v1; 
	// 아래 한줄 생각해봅시다.
	// => 우변은 임시객체
	// => 복습할 때, 아래 코드 메모리 그림 그려봐
	// c++ nullptr 지우는 것 허용함. 두번지워도 오케이
	vector v3 = vector{10};	
					// 1. 이순간 위에서 만든 복사 생성자 (깊은 복사 사용)
					// 2. 임시객체인 경우는 비효율적
					// 3. 임시객체는 자원의 복사가 아니라, 자원 뺏는 것이 효율적
					
}