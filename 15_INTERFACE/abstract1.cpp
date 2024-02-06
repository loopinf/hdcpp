// 152 page ~
// 추상 클래스

// 추상 클래스 : 순수 가상 함수를 포함하는 클래스
// key point : 객체를 만들수 없다.
// intention : 파생 클래스에서 반드시 구현해야 하는 함수를 정의하기 위해 사용한다.
class Shape
{
public:
	virtual void draw()  = 0;	// 순수 가상함수 (pure virtual function)
								// 함수의 구현이 없다.
								// ==> "= 0" 을 붙이면 됩니다.
};

class Rect : public Shape
{
	// draw() 를 구현하지 않았다.
	// ==> Rect 도 추상 클래스가 된다.
	// ==> 추상 클래스는 객체를 만들수 없다.
	// ==> 추상 클래스는 파생 클래스에서 반드시 구현해야 한다.
	// ==> 추상 클래스는 인터페이스 역할을 한다.
	// ==> 인터페이스 : 클래스의 사용법을 정의한 것
public:
	void draw() override {}
};

int main()
{
	Shape s; // ?
	Rect  r; // ?
}


