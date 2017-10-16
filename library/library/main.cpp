#include "Books.h"
#include "Book_search.h"
#include"Brrow_books.h"
#include"Manage_books.h"
#include"Reader.h"
#include"Reader_search.h"
#include"Replay_book.h"
#include "Reach.h"

void main()
{
	while (1)
	{
		cout << "<1>借书,<2>还书,<3>书籍管理,<4>读者管理,<5>搜索,<6>退出" << endl;
		int choice = -1;
		if (choice == 1)
			CBrrow_books;
		else if (choice == 2)
			CReplay_book;
		else if (choice == 3)
			CManage_books;
		else if (choice == 4)
			CReader;
		else if (choice == 5)
			CReach;
		else if (choice == 6)
			break;
		else
			cout << "输入有误！请重新输入" << endl;
	}
}