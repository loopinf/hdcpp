// 35 page

template <typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	// square : 
	square<int>(3); // compiler square(int) 
	square<double>(3.4);

	square(3); // compiler square(int)
	square(3.4); // compiler square(double)
}

// code bloat 
// 1. 컴파일러가 템플릿 함수를 만들때, 템플릿 인자의 타입에 따라 함수를 생성한다.
// 2. 템플릿 함수를 사용하는 모든 타입에 대해 함수를 생성한다.
// 3. 코드가 커진다.
// 4. 코드가 커지면 컴파일 시간이 늘어난다.
// 5. 코드가 커지면 메모리 사용량이 늘어난다.
// 6. 코드가 커지면 캐시 히트율이 떨어진다.
// 7. 코드가 커지면 실행시간이 늘어난다.
