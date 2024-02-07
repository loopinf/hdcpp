       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // function call
							// 1, 2 to some memory
							// call Add1
	int n2 = Add2(1, 2);  // binary code will be here
							// mov eax, 2
							// add eax, 1
							// mov n2, eax

	int(*f)(int, int) = &Add2;

// if ( user input == 1) { f = &Add1; }
	f(1, 2); //  not possible to ...do inline 
}

// keypoint 1.
// inline function은 함수 호출이 아니라 코드를 치환하는 것이다.