#include <iostream>
#include <string>
#include <vector>

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title{title} {}
	virtual ~BaseMenu() {} // 핵심!!, 만약 가상소멸자가 아니면, 
							// delete PopupMenu 시
							// PopupMenu 의 소멸자가 호출되지 않는 현상 발생
							// 
	
	std::string get_title() const { return title; }

	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu{title}, id{id} {}

	~MenuItem(){
		std::cout << get_title() << "menu destroyed\n";
	}
	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;  
public:
	PopupMenu(const std::string& title) : BaseMenu{title} {}

	~PopupMenu(){
		for (auto p: v)
		delete p;
		std::cout << get_title() << "menu destroyed\n";
	}

	void add(BaseMenu* m) { v.push_back(m); }


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
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2); 

	pm1->add(new MenuItem("RED",   11));
	pm1->add(new MenuItem("GREEN", 12));
	pm1->add(new MenuItem("BLUE",  13));

	pm2->add(new MenuItem("HD",  21));
	pm2->add(new MenuItem("FHD", 22));
	pm2->add(new MenuItem("UHD", 23));

	root->command();
	delete root;
}




