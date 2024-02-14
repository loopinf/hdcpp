// C 포인터의 단점 #1

void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	void(*f)(int);
	
	f = &f1;
	f = &f2;
}