#include <iostream>
#include <thread>

int main()
{
    std::cout << std::this_thread::get_id() << std::endl;

    std::thread::id tid1 = std::this_thread::get_id();

}