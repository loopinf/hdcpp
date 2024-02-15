// IPC.h
//----------------------------------------------------
class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

// Client 의 요청을 처리하는 함수
int handler(int code, int param1, int param2)
{
	switch (code)
	{
	case 1: return server.Add(param1, param2);
	case 2: return server.Sub(param1, param2);
	}
	return 0;
}

// int main()
// {
// 	//현재 프로세스를 ipc서버로 동작하게 하는 함수라고 가정
// 	StartServer("Calc", // 서버이름
// 				&handler); // client 가 요청을 보내면 호출될 함수 등록

// }





// client/server 간 통신을 시물레이션 하기 위한 함수
int find_server(const char* name) { return 1; }
int send_server(int server, int code, int param1, int param2) { return handler(code, param1, param2); }