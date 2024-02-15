#include <iostream>
#include "ipc.h"

// Proxy 는 다양한 이유로 UPDATE될 수 있음
// proxy가 변경되어도 client 가 수정되지 않게 하기 위해
// 약한 결합으로 설계

struct ICalcProxy
{
	/* data */
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalcProxy() {}
};

class Calc : public ICalcProxy
{
	int handle;

public:
	Calc() { int handle = find_server("Calc"); }
	int Add(int a, int b) { return send_server(handle, 1, a, b); }
	int Sub(int a, int b) { return send_server(handle, 2, a, b); }
};
// 핵심 : Calc 라는 Proxy는 서버 제작자가 만들게 합니다.

int main()
{
	// 클라이언트 제작자가 proxy를 사용할때, 아래처럼 사용하면,
	// "강한 결합(tightly coupling)" 이 됩니다.
	// Calc *c = new Calc;

	// keypoint
	ICalcProxy* c = new Calc; // ? 
								// 1. proxy가 담긴 동적모듈 (.so, .dll)을 load하고
								// 2. 동적모듈안에 약속된 함수 (CreateProxy같은)를 만들고
								// 3. 약속된 함수에서 실제 Proxy를 생성해서 ICalcProxy* 로 반환
								// => 즉 클라이언트 제작자는 오직 ICalcProxy 만 사용하게됨

	int ret1 = c->Add(1, 2); //  ipc ,
	int ret2 = c->Sub(1, 2);
}