#include <iostream>
#include <vector>

// 3. all shape class should have draw() function
//    so that we can call draw() function through Shape pointer
class Shape
{
public:
    virtual void draw() { std::cout << "Shape draw" << std::endl; }
};
class Rect : public Shape
{
public:
    void draw() { std::cout << "Rect draw" << std::endl; }
};

class Circle : public Shape
{
public:
    void draw() { std::cout << "Circle draw" << std::endl; }
};
int main()
{
    // Rect *buff[10];         // Rect 만 저장 가능
    Shape *buff[10];        //
    std::vector<Shape *> v; // Shape 만 저장 가능
    while (1)
    {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) { v.push_back(new Rect); }
        else if (cmd == 2) { v.push_back(new Circle); }
        else if (cmd == 9)
        {
            for (auto e : v) // e : Shape*
                e->draw();   // error, Shape::draw() is not exist
        }
    }
}
// why error,
// ==> e : Shape* , Shape::draw() is not exist
// Solution ?
// 1. Shape class에 draw() 추가
// 2. e Rect* or Circle* 로 변환
// 2. dynamic_cast<Rect*>(e) : Rect* 로 변환