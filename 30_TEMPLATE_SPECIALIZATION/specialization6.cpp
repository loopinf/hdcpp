// C++98 시절 만든 버전 
template<typename T>
struct plus 
{
	int operator()(T a, T b) const 
	{
		return a + b;
	}
};

// C++14 : class template 이 아닌 함수 template으로 하자.
        // 즉 operator() 자체를 template으로
        // plus<int>    : C++98 버전사용
        // plus<특정타입>: C++14 버전사용
        // 특정타입 : 모든 C++ 코드에서 plus 사용시 전달하지 않았을 타입!

template<>
struct plus<특정타입>
{
    template<typename T1, typename T2>
	int operator()(T1 a, T2 b) const 
	{
		return a + b;
	}
};

int main()
{
	plus<int> p;

	auto ret1 = p(1, 2);  // ok
	auto ret2 = p(1, 2.1); // ?

}