#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> up1(new int); //ok
    std::unique_ptr<int> up2(new int[10]); //??

}