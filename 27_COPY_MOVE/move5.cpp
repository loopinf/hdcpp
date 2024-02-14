#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;
	std::string s4 = std::move(s2);

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}