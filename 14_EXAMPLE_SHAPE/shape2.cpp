#include <iostream>
#include <vector>

class Shape
{
};
class Rect : public Shape
{
public:
    void draw()
    {
        std::cout << "Rect draw" << std::endl; }
};

class Circle : public Shape
{
public:
    void draw() { std::cout << "Circle draw" << std::endl; }
};
int main()
{
    Rect *buff[10]; // Rect 만 저장 가능
    Shape* buff[10]; // 
    std::vector<Shape*> v; // Shape 만 저장 가능
}