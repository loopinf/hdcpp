
#include <iostream>

// tightly coupled
// => one class uses another class directly by name (not through an interface)
// => not extendable, not maintainable

// loosely coupled
// => one class uses another class through an interface
// => extendable, maintainable

// ======================================================

// abstract class : rules to follow + some member   
// interface       : rules to follow (pure virtual functions) only

// C#, Java : interface, abstract keyword 
// C++      : not exact keyword  (abstract class, pure virtual function)


// RULE:
// 1. All cameras have a common interface derived from a base class
//    All cameras should implement the same interface 

class ICamera
{
public:
    virtual void take() = 0;
    virtual ~ICamera() {}    // interface is actually a base class
                             // destructor should be virtual
};
struct ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {}    // interface is actually a base class
                             // destructor should be virtual
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
