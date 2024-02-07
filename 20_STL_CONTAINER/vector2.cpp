// 동적 배열 개념
#include <iostream>
#include <cstring>
int main()
{
	int size = 4;
	int *x = new int[size];
	// int x[4] = {1, 2, 3, 4};   // can't delete x[4]
	int num = 0;
	int idx = 0;

	// want to get user input until user input -1
	// all user input will be stored in x
	while (true)
	{
		/* code */
		std::cin >> num;
		if (num == -1)
		{
			break;
		}
		x[idx++] = num;
		if (idx == size)
		{
			// increase the size of x
			int *tmp = new int[size * 2];
			// copy the content of x to temp
			// for (int i = 0; i < size; i++) { temp[i] = x[i]; }
			memcpy(tmp, x, sizeof(int) * size);
			// delete x
			delete[] x;
			x = tmp;
		}
	}

	// x 의 크기를 변경할수 있을까 ?
	std::cout << "added num " << idx << std::endl;
	std::cout << "size of x " << sizeof(x) << std::endl;
	delete[] x;
}