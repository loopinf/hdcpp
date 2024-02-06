class Base
{
private:   	// 멤버 함수에서만 접근 가능
	int a;	

protected: 	// 멤버 함수와 파생 클래스의 멤버 에서 접근 가능
	int b;	

public:    	// 모든 함수에서 접근 가능
	int c;	

	void set_a(int v) { a = v;}
};

class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;	
		b = 0;  
		c = 0;  
	}
};
int main()
{
	Base base;
	base.a = 0; 
	base.b = 0; 
	base.c = 0; 
}
