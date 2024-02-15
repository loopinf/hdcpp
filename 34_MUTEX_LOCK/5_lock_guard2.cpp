#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
	// C++ STL
	// std::adopt_lock_t 모두 있습니다. 
	std::lock_guard<std::mutex> lg(m);
	std::cout << "using shared data" << std::endl;
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	t1.join();
	t2.join();
}



