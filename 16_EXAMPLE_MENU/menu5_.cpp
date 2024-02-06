#include <iostream>
#include <string>
#include <vector>

// C 언어: memory diagram .. memory structure
// C++: 객체지향 프로그래밍, Class diagram

class BaseMenu
{
    std::string title;
public:
    BaseMenu(const std::string &title) : title{title} {}
    std::string get_title() const { return title; }
    virtual void command()  = 0;
};
class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(const std::string &title, int id)
        : BaseMenu{title}, id{id} {}
    void command()
    {
        std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    std::vector<BaseMenu *> v;
public:
    PopupMenu(const std::string &title) : BaseMenu{title} {}
    void add(BaseMenu *mi) { v.push_back(mi); }

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

            if (cmd < 1 || cmd > sz + 1)
                continue;
            v[cmd - 1]->command(); // v[0] => m1, v[1] => m2
        }
    }
};
int main()
{
    PopupMenu* root = new PopupMenu("Root Menu");
    PopupMenu* pm1 = new PopupMenu("Change color");
    PopupMenu* pm2 = new PopupMenu("Change resolution");

    root->add(pm1);
    root->add(pm2);

    pm1->add(new MenuItem("RED", 11));
    pm1->add(new MenuItem("GREEN", 12));

    pm2->add(new MenuItem("1024x768", 21));
    pm2->add(new MenuItem("1920x1080", 22));

    root->command();
}

