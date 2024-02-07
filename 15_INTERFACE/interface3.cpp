
#include <iostream>

// Camera and User should have a common interface

// RULE:
// 1. All cameras have a common interface derived from a base class

class ICamera
{
public:
    virtual void take() = 0;
};

class People
{
public:
    void use_camera(ICamera *c) { c->take(); }
};

class Camera : public ICamera
{
public:
    void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
    void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDcamera : public ICamera
{
public:
    void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
    People p;
    Camera c;

    p.use_camera(&c);
    HDCamera hc;
    p.use_camera(&hc); // take picture
    UHDcamera uhc;
    p.use_camera(&uhc); // take picture
}
