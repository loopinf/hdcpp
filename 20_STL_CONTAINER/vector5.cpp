#include <iostream>
#include <string.h>
// #include <string>
template <typename T>
class vector
{
    // what kind of member variable should be here?
    T *ptr;
    int sz;

public:
    vector(int sz) : sz{sz} { ptr = new T[sz]; }
    ~vector() { delete[] ptr; }
    void resize(int new_sz)
    {
        if (new_sz > sz)
        {
            int *tmp = new T[new_sz];
            memcpy(tmp, ptr, sizeof(T) * sz);
            delete[] ptr;
            ptr = tmp;
            sz = new_sz;
        }
    }
    T& operator[](int idx) { return ptr[idx]; }
};
int main()
{
    vector<int> v(4);
    v[0] = 10; // v.operator[](0) = 10;

    vector<double> v2(4);
    v2[0] = 3.4;
    std::cout << v2[0] << std::endl;
}
// #include <vector>

// int main()
// {
// 	std::vector<int> v(5); // 5개를 0으로

// 	v[0] = 10;   // v.operator[](0) = 10;
// }
// int x = 0;
// int f1() { return x; }
// int &f2() { return x; }
// // int f1() = 10;  // error
// int &f2() = 10; // ok
