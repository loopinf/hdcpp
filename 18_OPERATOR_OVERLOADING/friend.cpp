#include <iostream>

// friend 문법 - 75 page

class Bike
{
private:
	int gear = 0;

public:
	//	void set_gear(int n) { gear = n; }
	//  not a member , but a friend so it can access private members
	friend void fix_bike();
};

void fix_bike()
{
	Bike b;
	b.gear = 10;
}

int main()
{
	fix_bike();
}