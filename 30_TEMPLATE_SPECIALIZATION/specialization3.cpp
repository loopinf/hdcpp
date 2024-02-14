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

	T& operator[](int idx) { return ptr[idx]; }
};

struct bit_proxy
{
	int* ptr;
	std::size_t idx;

	bit_proxy(int* p, std::size_t idx) : ptr{p}, idx{idx} {}

	bit_proxy& operator=(bool value)
	{
		printf("%p 주소의 %zd 번째 비트를 %d 로 설정\n", ptr, idx, value);

		return *this;
	}

	operator bool() 
	{ 
		printf("%p 주소의 %zd 번째 비트값을 반환\n", ptr, idx);
		return false;	
	}
};

template<>
class vector<bool>
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new int[(sz/32) + 1];
	}
	~vector() { delete[] ptr; }

	bit_proxy operator[](std::size_t idx) { return bit_proxy{ptr, idx}; }
};

int main()
{
	vector<bool> v1(100);

	v1[3] = true;

	bool b = v1[3];
}

