#include <iostream>
#include <memory>

void foo(void *p) { free(p); }
struct Freer
{
    inline void operator()(void *p) const
    {
        free(p);
    }
};
int main()
{
    // shared_ptr : 생성자 2번째 인자로 삭제자 함수 전달
    std::shared_ptr<int> sp1(static_cast<int *>(malloc(sizeof(int))), foo);

    // unique_ptr :  template 2번째 인자로 함수객체 전달
    std::unique_ptr<int, Freer> up1(static_cast<int *>(malloc(sizeof(int))));

    // shared_ptr : control_block 에 삭제자(주소등)를 저장했다가 사용가능
    // unique_ptr : template 인자이므로 저장공간이 없이도 소멸자에서 사용가능

    // shared_ptr : 삭제자를 변경해도 같은 타입, same container
    std::shared_ptr<int> sp1(할당, 삭제자1);
    std::shared_ptr<int> sp2(할당, 삭제자2);
    std::unique_ptr<int, DELETER1> up1(할당 );
    std::unique_ptr<int, DELETER2> up2(할당 );

}