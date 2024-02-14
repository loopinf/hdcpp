// 1복사
#include <iostream>
// 객체지향 언어의 오류처리 : 예외 전달

int db_backup()
{
	if (1)
        throw 1;  // 실패시 "예외를 던진다"
                    // 호출자가 예외를 잡지 않으면 프로그램은 비정상 종료됨
		// return -1;  // 이렇게 하면 호출자가 무시할 수 있습니다. 

	return 100;
}
void db_remove() {}

int main()
{
	int ret = db_backup(); // 함수가 예외를 던졌을때 처리하지 않으면, 프로그램은 비정상 종료됨
	db_remove();
}
