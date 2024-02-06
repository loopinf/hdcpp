class Animal
{
// public:  // no error 
// private:   // 1, 2 all error
// protected:  // 1 error, 2 no error
// => protected constructor can't create an object of a class 
// => but can be used in derived class

// abstract class, <->  concrete class
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	// Dog() : Animal() {}  //  compiler adds this line
};

int main()
{
	Animal a;  //1
	Dog d;
}