#include <iostream>

class vector 
{
public:
	vector(std::size_t size) {}
};

void foo(vector& v)       {std::cout << "1\n";}
void foo(const vector& v) {std::cout << "2\n";}

int main()
{
	vector v{10};

	foo(v);
	foo(vector{10});
}