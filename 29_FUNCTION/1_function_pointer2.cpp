// C 포인터의 단점 #2
// => 일반 함수 포인터에 멤버함수의 주소를 담을 수 없음
class Dialog 
{
public:
	void close(int code) {}  // void close(Dialog* this, int code)
};
void f1(int a) {}

int main()
{
	void(*f)(int);
	
	f = &f1;			// ok
	// f = &Dialog::close;  // error, close 함수는 인자가 2개임.

//  ------------------------------------------------------
	void(*f1)(int);  // non member function 주소담는 포인터
	void(Dialog::*f2)(int) = &Dialog::close;  // member function pointer

	f2(0); // error , this 가 없음
	Dialog dlg;
	dlg.f2(0); // error, dlg 가서 f2라는 멤버를 찾으나, 실패

	// .* 연산자 (pointer to member operator) 사용
	dlg.*f2(0); // pointer, 연산자 우선순위때문에 문제.
	(dlg.*f2)(0); // ok, 이코드가 멤버함수포인터에 주소를 담았다가 호출하는 코드


}