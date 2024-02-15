#include <iostream>
#include "ipc.h"

// 서버를 대신할 클래스를 만듬
// remote proxy pattern
class Calc{
	int handle;
	public:
	Calc(){ int handle = find_server("Calc");}
	int Add(int a, int b){ return send_server(handle, 1, a, b);}
	int Sub(int a, int b){ return send_server(handle, 2, a,b);}

}
int main()
{
	// 서버와 통신하고 싶다면, 서버의 대행자 (Proxy)를 사용하면 됨
	// IPC몰라도 됨
	Calc * c = new Calc;

	int ret1 = c->Add(1,2); // 
	int ret2 = c->Sub(1,2);
}
// 위처럼 코드를 만들면
// => 서버는 한개라도 여러개의 client 가 있을 수 있음
// 1. 모든 클라이언트 제작자가 ipc기술을 알아야 한다.

// 2. 1,2 등의 명령코드를 외워야 함

// 3. 서버가 자주 down되서, 백업서버를 만들었다면, 모든 클라이언트가 수정되어야함