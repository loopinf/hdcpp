template <typename T>
T square1(T a)
{
    return a * a;
}

template <class T>  // exactly same with typename T , it starts with class
T square2(T a)
{
    return a * a;
}

// from C++20 , template very simple
// g++ 01_TEMPLATE/01_template4.cpp -std=c++20
auto square3(auto a)  // exactly same with typename T 
{
    return a * a;
}
