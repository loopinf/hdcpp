#include <iostream>
#include <string>

// 128 page ~

// C++     : class Student : public Person
// C#      : class Student : Person
// Java    : class Student extends Person
// Python  : class Student(Person)
// Rust    : no inheritance

// Terminology
// Person  :     Base class,  Super class,  Parent class
// Student :  Derived class, 	Sub class,   Child class

class Person
{
protected:
	std::string name;
	int age;
};

class Student : public Person
{
	int id;
};

class Professor : public Person
{
	int major;
};

int main()
{
	Student s;
	Professor p;
}
