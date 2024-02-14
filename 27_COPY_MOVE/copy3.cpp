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
    // 깊은 복사로 구현한 복사 생성자
    vector(const vector& other): sz{other.sz}
    {
        // 1. pointer가 아닌 멤버는 그대로 복사
        // sz = other.sz;  // initialize list 에서
        // 2. pointer는 주소를 복사하지 말고
                // 메모리 할당후,메모리 내용을 복사
        ptr = new int[sz];
        memcpy(ptr, other.ptr, sizeof(int)* sz);
    }
};
int main()
{
	vector v1{10};  // 메모리 모양 생각해보세요.
	vector v2 = v1; // 현재 이코드때문에 runtime error
					// vector v2{v1} 거의 동일 (약간의 차이 있음)
					// 컴파일러가 제공하는 복사 생성자를 사용
					// 동일한 메모리 두번 지우면, undefined. 디버깅 모드에서는 죽음
}