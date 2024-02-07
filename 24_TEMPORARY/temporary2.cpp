#include <iostream>

void draw_line(int x1, int y1, int x2, int y2) {}

int main()
{
	// draw a line from (10,10) to (20,20)

	// 1. make a variable and pass as argument
	int x1 = 10, y1 = 10;
	int x2 = 20, y2 = 20;

	draw_line(x1, y1, x2, y2);
	// 2. literal 
	draw_line(10, 10, 20, 20);
}