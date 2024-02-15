// C++98 시절 만든 버전 
template<typename T=void>
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
        // plus<void>: C++14 버전사용
        // 특정타입 : 모든 C++ 코드에서 plus 사용시 전달하지 않았을 타입!
        //  => void

template<>
struct plus<void>
{
    template<typename T1, typename T2>
	int operator()(T1 a, T2 b) const 
	{
		return a + b;
	}
};

int main()
{
	plus<int> p1;  // C++98 version, 2개의  인자는 모두 int취급
    plus<void> p2; // C++14 버전 사용. 2개 인자 타입 달라도 됨
    plus<> p3; // plus<void> 와 동일

    plus p4;  // C++17 부터 가능. T=void 이므로, plus<void>

    // std::sort(v.begin(), v.end(), std::less<int>{}); // 이렇게 오케이
    // std::sort(v.begin(), v.end(), std::less{});   // 이렇게도 가능 
}