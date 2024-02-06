#include <iostream>
#include <string>
#include <vector>

class MenuItem
{
    std::string title;
    int id;

public:
    MenuItem(const std::string &title, int id)
        : title{title}, id{id} {}
    std::string get_title() const { return title; }
    void command()
    {
        std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
        getchar();
    }
};

class PopupMenu
{
    std::string title;
    std::vector<MenuItem *> v;

public:
    PopupMenu(const std::string &title) : title{title} {}
    void add(MenuItem *mi) { v.push_back(mi); }

    void command()
    {
        while (1)
        {
            system("clear");
            auto sz = v.size();
            for (int i = 0; i < sz; i++)
            {
                std::cout << i + 1 << "." << v[i]->get_title() << std::endl;
            }
            std::cout << sz + 1 << ". Out" << std::endl;
            std::cout << "메뉴를 선택하세요 >> ";

            int cmd;
            std::cin >> cmd;
            if (cmd == sz + 1)
                break;

            if ( cmd < 1 || cmd > sz + 1)
                continue;
            v[cmd - 1]->command(); // v[0] => m1, v[1] => m2
        }
    }
};
int main()
{
    MenuItem m1("김밥", 11);
    MenuItem m2("라면", 12);

    // m1.command(); // 메뉴를 선택하면 호출할 함수!
    PopupMenu pm("Today's Lunch Menu");
    pm.add(&m1);
    pm.add(&m2);

    pm.command();
    // 1. 김밥
    // 2. 라면
    // 3.
}
