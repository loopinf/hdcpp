// 3복사
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

    // want to find the multiple of k
    // => normal function can't be used

    int k = 3; // user input
	auto ret1 = std::find_if(v.begin(), v.end(), foo); 
	std::cout << *ret1 << std::endl; // 9

    auto ret2 = std::find_if(v.begin(), v.end(),
                      [k](int n) { return n % k == 0; }
                      );
    
    

}
