#include <iostream>
#include <vector>

// 5. OCP principle : Open Close Principle
// ==> Open : 확장에는 열려 있고, 
// ==> Close :  수정에는 닫혀 있어야 한다.

class Shape
{
    int color;
public:
    virtual void draw() { std::cout << "Shape draw" << std::endl; }
    void set_color() { color = 0; }
    virtual int get_area() const { return 0; }
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
// Added later
class Triangle : public Shape
{
public:
    void draw() { std::cout << "Triangle draw" << std::endl; }
};
int main()
{
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
                e->draw();   // polymorphism
                // OOP, 1. encapsulation, 2. inheritance, 3. polymorphism
        }
    }
}