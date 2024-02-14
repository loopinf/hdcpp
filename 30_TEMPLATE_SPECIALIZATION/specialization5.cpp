
struct plus 
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

int main()
{
	plus p;

	auto ret1 = p(1, 2);
	auto ret2 = p(1, 2.1);
}