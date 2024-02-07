#include <iostream>

// friend 문법 - 75 page

class Bike
{
private:
	int gear = 0;
	
public:
//	void set_gear(int n) { gear = n; }

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