#include <iostream>

class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class People
{
public:
	void use_camera(Camera* c)   { c->take(); }
};

int main()
{
	People p;
	Camera c;

	p.use_camera(&c);	
}

