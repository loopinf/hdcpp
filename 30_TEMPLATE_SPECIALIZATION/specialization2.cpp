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
	vector<int>  v1(100);
	vector<bool> v2(100);
}

