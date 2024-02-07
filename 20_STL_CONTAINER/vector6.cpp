#include <iostream>
#include <vector>

// STL : C+++ standard library
// => Standard Template Library

int main()
{
    std::vector<int> v1(4,0); // 4개를 0으로

    // 
    v1[0] = 10;   // v.operator[](0) = 10;
    v1.resize(10);
}
// vector 's "github.com/codenuri/advancedcpp"