int main()
{
	const int c = 10;

	// c의 주소를 double* 에 담고 싶습니다.
	double* p = (double*)&c;
	// double* p = &c; // ?
	// double* p = static_cast<int*>(&c);
	double* p = reinterpret_cast<double*>(&c);
	// const_cast<int*>(&c)

}





