#include "Reach.h"



CReach::CReach()
{
	while (1)
	{
		cout << "<1>�鼮����,<2>ѧ������" << endl;
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
			cout << "������������������" << endl;
	}
}


CReach::~CReach()
{

}
