#include "Reach.h"



CReach::CReach()
{
	while (1)
	{
		cout << "<1>书籍搜索,<2>学号搜索" << endl;
		int choice = -1;
		cin >> choice;
		rewind(stdin);
		if (choice == 1)
		{
			CBook_search();
			break;
		}
		else if (choice == 2)
		{
			CReader_search();
			break;
		}
		else
			cout << "输入有误！请重新输入" << endl;
	}
}


CReach::~CReach()
{

}
