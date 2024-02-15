#include <iostream>

template<typename T>
class vector 
{
	T* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new T[sz];
	}
	~vector() { delete[] ptr; }

	T& operator[](int idx) { return ptr[idx]; }
};

struct bit_proxy
{
	int* ptr;        // 버퍼의 주소
	std::size_t idx; // 접근할 인덱스 (비트단위)

	bit_proxy(int* p, std::size_t idx) : ptr{p}, idx{idx} {}

	bit_proxy& operator=(bool value)
	{
		printf("%p 주소의 %zd 번째 비트를 %d 로 설정\n", ptr, idx, value);

		return *this;
	}

	operator bool() 
	{ 
		printf("%p 주소의 %zd 번째 비트값을 반환\n", ptr, idx);
		return false;	
	}
};

template<>
class vector<bool>
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new int[(sz/32) + 1]; // sz 100 -> new int[4] 
	}
	~vector() { delete[] ptr; }

	// 아래처럼 하면 byte (8bit)단위로 메모리 접근하게 됨.
	// bool& operator[](int idx) { return ptr[idx]; } // T 대신 bool 쓰면  byte 단위로 리턴됨 
	//  이럴때 사용하는 기술 "temporary proxy" 
	// => 널리 알려진 기술임
	bit_proxy operator[](std::size_t idx) { return bit_proxy{ptr, idx}; }

};

int main()
{
	vector<bool> v1(100);

	v1[3] = true;    // bit_proxy_임시객체 =  true
						// 임시객체.operator=(true);
						// 즉. bit_proxy 클래스에 대입연산자가 있어야 함

	bool b = v1[3];  // boll b = bit_proxy_임시객체
						// boll b = 임시객체.operator bool() 
						// 즉. bit_proxy 클래스에는 operator bool() 이 있어야 함 
}

// google "C++ Idioms"
// C++ 진영에서 사용되는 전형적인 기술 (코딩패턴)에 이름 붙인거
