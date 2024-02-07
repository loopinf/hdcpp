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
};
int main()
{
    vector v(4);
    v.resize(10);
}