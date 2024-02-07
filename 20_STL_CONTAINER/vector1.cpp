// 배열의 단점
#include <iostream>
int main()
{
	int x[4] = {1,2,3,4};
	int num = 0;
	int idx = 0;

	// want to get user input until user input -1
	// all user input will be stored in x
	while (true)
	{
		/* code */
		std::cin>>num;
		if (num == -1)
		{
			break;
		}
		x[idx++] = num;
	}
	
	// x 의 크기를 변경할수 있을까 ?
}