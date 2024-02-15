// C 포인터의 단점 #1
// => signature (return type and arg ) 동일한 주소만 담을 수 있음 
void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	void(*f)(int);
	
	f = &f1;  // ok
	f = &f2;  // error.
}