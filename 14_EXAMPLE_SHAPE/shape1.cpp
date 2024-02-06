#include <iostream>
#include <vector>

// 145page ~
// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.
// 2. Base class would be convinient
class Shape
{
};
class Rect : public Shape
{
    // int x, y, width, height; // constructor omit
public:
    void draw()
    {
        std::cout << "Rect draw" << std::endl;
    }
};

class Circle : public Shape
{
public:
    void draw() { std::cout << "Circle draw" << std::endl; }
};
int main()
{
    Rect *buff[10]; // Rect 만 저장 가능
    // created order in
    Shape* buff[10]; // 
    std::vector<Shape*> v; // Shape 만 저장 가능
}
