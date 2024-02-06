class Shape
{
public:
	virtual void Draw() {};
	virtual void Move() {};
};
class Rect : public Shape
{
public:
	// #1. 가상함수를 override 할때는 virtual 은 있어도 되고 없어도 됩니다.
	// => virtual 을 붙이지 않아도 기반 클래스에서 virtual 로 선언되었기때문에 virtual 입니다.
	virtual void Draw()  {};

	// #2. virtual function override , typo will make new function
//	virtual void draw() {};
//	virtual void Move(int n) {};

	// override C++11 
	virtual void draw() override {};
	virtual void Move(int n) override {};
};

int main()
{
	
}