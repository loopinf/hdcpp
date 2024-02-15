#include <iostream>

template<typename T>
class vector 
{
	T* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new T[sz];
	}
	~vector() { delete[] ptr; }

	T& operator[](std::size_t idx) { return ptr[idx]; }
};

int main()
{
	vector<int>  v1(100);  // ok no problem. not a bad code
	vector<bool> v2(100);  // ok, compile pass, memory structure
							// 단점: sizeof(bool) * 100 이면 100 byte 임
							// 100bit 만 할당해도 되지 않나요?
}

