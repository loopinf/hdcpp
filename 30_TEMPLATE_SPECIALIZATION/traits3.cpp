#include <iostream>
#include <type_traits>

// traits2.cpp 는 에러 아닌데, 
// 아래코드는 컴파일 에러임
// why?

template<typename T> 
void printv(const T& value)
{
	if ( std::is_pointer<T>::value)
		std::cout << value << " : " << *value << std::endl;
	else 
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}