// 67page
#include <iostream>

// OOP, define new data type
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

// int get_rect_area(Rect rc)
int get_rect_area( const Rect& rc)
// int get_rect_area(int left, int top, int right, int bottom)
{
	return (rc.right - rc.left) * (rc.bottom - rc.top);
}

// void draw_rect(int left, int top, int right, int bottom)
void draw_rect(const Rect& rc)
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	Rect rc = {1,1,10,10};
	int n1 = get_rect_area(1, 1, 10, 10);
	// draw_rect(1, 1, 10, 10);
	draw_rect(rc);
}