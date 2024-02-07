// 3복사
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

 // #1. conditioner  normal function
	auto ret1 = std::find_if(v.begin(), v.end(), foo); 
	std::cout << *ret1 << std::endl; // 9

    // #2. conditioner  lambda
    // => function's name 
    // => [] : lambda introducer. it is not array. it tells compiler that it is lambda

    auto ret2 = std::find_if(v.begin(), v.end(), [](int n) { return n % 3 == 0; });
    auto ret2 = std::find_if(v.begin(), v.end(), [](int n) { return n % 3 == 0; }
    
    

}
