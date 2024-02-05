struct BigData
{
	int buff[1024];
};

void foo(int n)   // call by value , not change the original value
{
	n = 20;
}
// void goo( BigData bd )  // call by value, memory overhead
// void goo( BigData& bd )  // call by reference
void goo( const BigData& bd) // const & ==> call by reference, but read-only
{
}
int main()
{
	int x = 100;
	foo(x);

	BigData b;
	goo(b);
}
