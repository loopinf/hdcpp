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
	vector(const vector& other) : sz{ other.sz} 
	{
		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);

		std::cout << "copy ctor\n";
	}
	/*
	vector(vector&& other) : ptr{other.ptr} , sz{ other.sz} {
		other.ptr = nullptr;
		std::cout << "move ctor\n";
	 }
	*/
};
int main()
{
	vector v1{10};
	vector v2 = v1;           // 복사 생성자 사용 - 
	vector v3 = vector{10};	
	
	// lvalue 를 rvalue로 casting 한 경우, 깊은 복사가 아닌 이동할 수 있음
	vector v4 =static_cast<vector&&>(v1); 
	// v1 안쓸때
	vector v5 =std::move(v2); //  위함수와 동일함함, rvalue cast 가 맞는 말임
	// std::move
	// 1. 자원을 빼앗는 일을 하는 것이 아님
	// 2. 단지 인자로 받은 객체를 rvalue로 casting 만 함.
	// 3. 캐스팅의 결과로 vector의 복사생성자가 아닌 이동생성자가 호출됨
	// 4. 즉 실제 이동기능은 vector class 설계자가 만든것
	
	// std::move 사용
	// vector에 move 생성자가 없다면!?
	// => 에러는 아니고, 복사생성자 사용
	// => 즉 , 이동 될 수 는 없지만, std::move() 를 사용하는 것 자체는 문제없음

	// 이동생성자는
	// 1. 임시객체 만을 위한 것이 아니라
	// 2. 이름있는 객체도 다양한 이유로, std::move(v1) 처럼 사용하려고 만든 것

}
// rvalue의 종류
// prvalue : pure rvalue , 태생부터 순수한 rvalue, 임시객체, 3 같은 literal
// xvalue  : expire value  캐스팅 또는 std::move 를 통해서 rvlaue 된 것들
//				이름(id)가 있었는데, move 생성자를 호출하기 위해 rvalue로 변경한것
