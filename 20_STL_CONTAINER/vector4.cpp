#include <iostream>
// vector 기본 구현
#include <iostream>
#include <string.h>
// #include <string>

class vector
{
    // what kind of member variable should be here?
    int *ptr;
    int sz;

public:
    vector(int sz) : sz{sz} { ptr = new int[sz]; }
    ~vector() { delete[] ptr;}
    void resize(int new_sz)
    {
        if (new_sz > sz)
        {
            int* tmp = new int[new_sz];
            memcpy(tmp, ptr, sizeof(int) * sz);
            delete[] ptr;
            ptr = tmp;
            sz = new_sz;
        }
    }
	int& operator[](int idx) { return ptr[idx]; }
};
int main()
{
    vector v(4);
	v[0] = 10;   // v.operator[](0) = 10;
}
// #include <vector>

// int main()
// {
// 	std::vector<int> v(5); // 5개를 0으로

// 	v[0] = 10;   // v.operator[](0) = 10;
// }
int x = 0;
int f1() { return x; }
int& f2() { return x; }
int f1() = 10; // error
int& f2() = 10; // ok
