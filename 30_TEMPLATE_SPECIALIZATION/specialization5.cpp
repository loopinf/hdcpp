// 아래 코드가 실제 C++표준에 있습니다. 
// C++98 시절 만든 버전 
template<typename T>
struct plus 
{
	int operator()(T a, T b) const 
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