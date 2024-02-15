#include <iostream>
#include "ipc.h"

int main()
{
	int handle = find_server("Calc");

	int ret1 = send_server(handle, 1, 1, 2);
	int ret2 = send_server(handle, 2, 1, 2);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
}