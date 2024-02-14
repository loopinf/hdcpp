// C 포인터의 단점 #2

class Dialog 
{
public:
	void close(int code) {}
};
void f1(int a) {}

int main()
{
	void(*f)(int);
	
	f = &f1;
	f = &Dialog::close;
}