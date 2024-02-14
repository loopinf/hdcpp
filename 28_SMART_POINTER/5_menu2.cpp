#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title{title} {}
	virtual ~BaseMenu() {}
	
	std::string get_title() const { return title; }

	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu{title}, id{id} {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<std::shared_ptr<BaseMenu>> v;  
public:
	PopupMenu(const std::string& title) : BaseMenu{title} {}

	void add(std::shared_ptr<BaseMenu> m) { 
        // v.push_back(m);  // 복사생성자 사용
        v.push_back(std::move(m));  // move  사용
        
        }


	void command()
	{
		while (1)
		{
			system("clear"); // linux
		//  system("cls")	 // windows

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();	
		}
	}
};

int main()
{
	std::unique_ptr<PopupMenu> root = std::make_unique<PopupMenu>("root");
	std::unique_ptr<PopupMenu> pm1 = std::make_unique<PopupMenu>("색상 변경");
	std::unique_ptr<PopupMenu> pm2 = std::make_unique<PopupMenu>("해상도 변경");


	pm1->add(std::make_unique<MenuItem>("RED",   11));
	pm1->add(std::make_unique<MenuItem>("GREEN", 12));
	pm1->add(std::make_unique<MenuItem>("BLUE",  13));

	pm2->add(std::make_unique<MenuItem>("HD",  21));
	pm2->add(std::make_unique<MenuItem>("FHD", 22));
	pm2->add(std::make_unique<MenuItem>("UHD", 23));

	root->add(std::move(pm1));
	root->add(std::move(pm2));

	root->command();
}



