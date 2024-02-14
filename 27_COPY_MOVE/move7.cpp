struct Object
{

};

int main()
{
    Object o1;
    Object o2 = o1;  // 항상 복사 생성자 사용
    Object o3 = std::move(o1); // 항상 이동생성자 호출
    Object o4 = std::move_if_noexcept(o2); // 이동생성자에 예외가 없으면 사용
    //  예외 가능성이 있으면 복사 생성자 사용

    std::vector<Object> v(3); // 3개
    v.resize(5); //
}