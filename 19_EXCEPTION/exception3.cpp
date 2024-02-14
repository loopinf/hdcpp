// 1복사
#include <iostream>

int db_backup()
{
    if (1)
        throw 1; // 실패시 "예외를 던진다"
                 // 호출자가 예외를 잡지 않으면 프로그램은 비정상 종료됨
                 // return -1;  // 이렇게 하면 호출자가 무시할 수 있습니다.

    return 100;
}
void db_remove() {}

int main()
{
    try
    {
        int ret = db_backup(); // 함수가 예외를 던졌을때 처리하지 않으면, 프로그램은 비정상 종료
    }
    catch(int e)
    {
        // 여기서 발생된 오류 처리함
        // 오류때문에 실행될 수 없다면 자원 정리, 안전하게 종료
        //  std::exit(-1);
    }
    db_remove();
}
