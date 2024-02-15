#include <vector>
#include <iostream>

int main()
{
	std::vector<int>  v1 = {1,2,3};
	std::vector<bool> v2 = {1,0,1};

	auto a1 = v1[0]; // int a1 = v1[0]
	auto a2 = v2[0]; // bit_proxy a2 = v2[0]

	std::cout << typeid(a1).name() << std::endl;
	std::cout << typeid(a2).name() << std::endl;
}