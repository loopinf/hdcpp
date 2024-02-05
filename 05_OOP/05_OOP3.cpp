// OOP2 복사
// 67page
// C struct : not possible to add method
// c++ struct: possible to add method

#include <iostream>

// OOP, define new data type
struct Rect
{
    int left;
    int top;
    int right;
    int bottom;

    // int get_rect_area(Rect rc)
    int get_area()
    // int get_rect_area(int left, int top, int right, int bottom)
    {
        return (right - left) * (bottom - top);
    }

    // void draw_rect(int left, int top, int right, int bottom)
    void draw()
    {
        std::cout << "draw rect" << std::endl;
    }
};
int main()
{
    Rect rc = {1, 1, 10, 10};
    int n1 = rc.get_area();  // get_area(&rc)
    // draw_rect(1, 1, 10, 10);
    rc.draw();
}