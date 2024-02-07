#include <iostream>
class Point
{
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    void print() const { std::cout << x << ", " << y << std::endl; }
};

// Point operator+(const Point &p1, const Point &p2)
// {
//     std::cout << "non-member operator+ called\n"; // "non-member operator+ called" 출력
//     return Point(p1.x + p2.x, p1.y + p2.y);
// }
int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    // member operator+ or non-member operator+ ? which one prefer?
    // some edge case :not possible member 
    int n = 3;
    Point p3 = p1 + p2; // p1.operator+(p2) // member operator+ called
    Point p4 = p2 + n ;
    Point p5 = n  + p2; // n ... member operater+ not possible
                        // operator+(n, p2) // non-member operator+ called


    // rule of thumb
    // if state of the object is changed, use member operator :  ++p1, p1 += p2
                            // -> , (), []. =

    // if state of the object is not changed, use non-member operator
}
