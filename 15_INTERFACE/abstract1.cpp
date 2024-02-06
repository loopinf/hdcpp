// 152 page ~
// 추상 클래스
class Shape
{
public:
	virtual void draw()  = 0;	
};

class Rect : public Shape
{
};

int main()
{
	Shape s; // ?
	Rect  r; // ?
}


