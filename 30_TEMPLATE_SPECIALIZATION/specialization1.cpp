#include <iostream>

template<typename T>
class MyContainer
{
public:
	void push_back(const T& arg) { std::cout << "T\n"; }
};

int main()
{
	MyContainer<int> 	mc1; mc1.push_back(0);
	MyContainer<int*> 	mc2; mc2.push_back(0);
	MyContainer<char*> 	mc3; mc3.push_back(0);
}