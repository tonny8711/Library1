#include "Reach.h"



CReach::CReach()
{
	while (1)
	{
		cout << "<1>�鼮����,<2>ѧ������" << endl;
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
			cout << "������������������" << endl;
	}
}


CReach::~CReach()
{

}
