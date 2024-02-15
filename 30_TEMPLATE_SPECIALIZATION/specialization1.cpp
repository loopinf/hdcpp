#include <iostream>

// primary template
template<typename T>
class MyContainer
{
public:
	void push_back(const T& arg) { std::cout << "T\n"; }
};
// partial specialization ( 부분 특수화, 부분 전문화)
template<typename T>
class MyContainer<T*>
{
public:
	void push_back(const T* arg) { std::cout << "T*\n"; }
};

// specialization 
template<>
class MyContainer<char*>
{
public:
	void push_back(const char* arg) { std::cout << "char*\n"; }
};

int main()
{
	MyContainer<int> 	mc1; mc1.push_back(0);
	MyContainer<int*> 	mc2; mc2.push_back(0);
	MyContainer<char*> 	mc3; mc3.push_back(0);
}