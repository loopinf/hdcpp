#include <iostream>
#include "ipc.h"
// 서버에 접속하기 위해 client 가 해야할 일

int main()
{
	// #1. 서버의 번호(핸들)를 찾는다.
	int handle = find_server("Calc");

	// #2. 서버에게 요청(int 3개)을 보낸다.
	int ret1 = send_server(handle, 1, 1, 2);
	int ret2 = send_server(handle, 2, 1, 2);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
}
// 위처럼 코드를 만들면
// => 서버는 한개라도 여러개의 client 가 있을 수 있음
// 1. 모든 클라이언트 제작자가 ipc기술을 알아야 한다.

// 2. 1,2 등의 명령코드를 외워야 함

// 3. 서버가 자주 down되서, 백업서버를 만들었다면, 모든 클라이언트가 수정되어야함