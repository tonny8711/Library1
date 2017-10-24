#include "Reach.h"



CReach::CReach()
{
	while (1)
	{
		cout << "<1>书籍搜索,<2>学号搜索" << endl;
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			Book_search();
			break;
		}
		else if (choice == 2)
		{
			Reader_search();
			break;
		}
		else
			cout << "输入有误！请重新输入" << endl;
	}
}


CReach::~CReach()
{

}
