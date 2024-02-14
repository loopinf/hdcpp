#include <iostream>

class vector 
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new int[sz];
	}
	~vector() { delete[] ptr; }

	// 복사생성자 : const vector& 이므로, lvalue, rvalue 모두 전달 가능
	// 				임시객체도 전달 가능
	// 				복사생성자만 있어도 에러는 안남
	vector(const vector& other) : sz{ other.sz} 
	{
		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);

		std::cout << "copy ctor\n";
	}
	// 임시객체 최적화
	vector(vector&& other) : ptr{other.ptr} , sz{ other.sz} {
		// 임시객체가 파괴될때 자원 삭제할 수 없도록, 자원주소를 0으로!!
		other.ptr = nullptr;
		std::cout << "move ctor\n";
	 }
};
int main()
{
	vector v1{10};
	vector v2 = v1;           // 복사 생성자 사용 - 
	vector v3 = vector{10};	
}
// copy ellision
// => C++ compiler 임시객체 제거하는 최적화 기법

// ~ C++14: copy ellision 이 최적화 기술
// C++17 ~: copy ellision 이 문법으로

// g++ 의 -fno-elide-contructors
// => copy ellision 하지 말라는 옵션

// g++ 소스.cpp -std=c++14 -fno-elide-constructors   : 임시객체 생성됨
// g++ 소스.cpp -std=c++17 -fno-elide-constructors   : 임시객체 제거됨
//   (copy ellision 이 최적화가 아닌 문법이므로)