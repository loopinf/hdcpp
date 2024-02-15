#include <iostream>
#include <type_traits>

// traits2.cpp 는 에러 아닌데, 
// 아래코드는 컴파일 에러임
// why?

// template<typename T> 
// void printv(const T& value)
// {
// 	if ( std::is_pointer<T>::value)
// 		std::cout << value << " : " << *value << std::endl;
// 	else 
// 		std::cout << value << std::endl;
// }
template<typename T> 
void printv(const T& value)
{
	// if constexpr : C++17 기술
	// => 조건이 false라면, "template => C++함수"를 만들때
	//    코드에 포함하지 마라
	// => 조건식은 반드시 "컴파일 시간에 조사가능" 해야 함
	//    일반변수는 사용할 수 없음.
	if constexpr ( std::is_pointer<T>::value)
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