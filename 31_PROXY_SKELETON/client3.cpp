#include <iostream>
#include "ipc.h"

class Calc{
	int handle;
	public:
	Calc(){ int handle = find_server("Calc");}
	int Add(int a, int b){ return send_server(handle, 1, a, b);}
	int Sub(int a, int b){ return send_server(handle, 2, a,b);}

};
// 핵심 : Calc 라는 Proxy는 서버 제작자가 만들게 합니다.

int main()
{
	// 클라이언트 제작자가 proxy를 사용할때, 아래처럼 사용하면,
	// "강한 결합(tightly coupling)" 이 됩니다.
	Calc * c = new Calc;

	int ret1 = c->Add(1,2); //  ipc , 
	int ret2 = c->Sub(1,2);
}