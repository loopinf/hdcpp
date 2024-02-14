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
	vector v3 = vector{10};	
}