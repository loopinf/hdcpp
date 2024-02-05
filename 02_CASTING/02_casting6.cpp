// const_cast : 상수성 제거를 위한 캐스팅

int main()
{
	int n = 10;
	
	const int* p = &n;

	// int* p1 = p;
	// int* p2 = static_cast<int*>(p);	
	// int* p2 = reinterpret_cast<int*>(p);

	int* p2 = const_cast<int*>(p);  // 


	const int c = 10;

	int* p3 = const_cast<
	
}
