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
	// 1. 함수 포인터 모양 알아두자
	void(*f1)(int) = &f1;   // & 생략가능, f1 으로도 가능하나, 암시적 형변환 되어서 그런것.
	void(Dialog::*f2)(int) = &Dialog::close; // & 반드시 필요

	// 2. 함수 포인터로 함수 호출하는 방법
	Dialog dlg;
	
	f1(10);			// non-member function pointer
	(dlg.*f2)(10);  // member function pointer
}