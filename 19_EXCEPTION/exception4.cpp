#include <iostream>
#include <string>

// exception 
struct file_not_found
{
    // 
    std::string file_name;
    file_not_found(const std::string& name) : file_name{name} {}
};

// empty class (member 없는 클래스)
// 이름자체가 설명이다
// sizeof(empty) 는 "1"
class disconnect_network {};

int db_backup()
{
	if (1)
        throw file_not_found{"a.txt"};  // 실패시 "예외를 던진다"
    if (2)
        throw disconnect_network{};
 
	return 100;
}
void db_remove() {}

int main()
{
    try{
	int ret = db_backup(); // 함수가 예외를 던졌을때 처리하지 않으면, 프로그램은 비정상 종료
    }
    catch( const file_not_found& e) { }
    catch( const disconnect_network& e) {}
    catch(...) // 나머지 error
    {}
	db_remove();
}
