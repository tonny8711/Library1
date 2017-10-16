#include "Manage_books.h"
#include "iostream"
#include   <functional> 
#include   <algorithm> 




CManage_books::CManage_books()
{
	cout << "添加书籍输入1\t删除书籍输入2\t修改书籍输入3" << endl;
	int import_num = 0;
	cin >> import_num;
	rewind(stdin);
	while (1)
	{
		if (import_num != 1 || import_num != 2 || import_num != 3)
		{
			cout << "输入有误，请重新输入" << endl;
			cin >> import_num;
		}
		else
			break;
	}
	if (import_num == 1)
	{
		cout << "请输入书名:";
		cin >> book;
		creat_books( book );
		book = "\0";
	}
	if (import_num == 2)
	{
		cin >> book;
		delete_books(book);
		book = "\0";
	}
	if (import_num == 3)
	{
		cin >> book;
		alter_books(book);
		book = "\0";
	}
}

void CManage_books::creat_books(string book)
{
	if (books.find( book) == books.end())
	{
		string num_book = "\0";
		cout << "请输入书号:";
		cin >> num_book;
		rewind(stdin);
		book_ID.insert(make_pair(book, num_book));
		ID_book.insert(make_pair( num_book, book));
		string author;
		cout << "请输入作者:";
		cin >> author;
		rewind(stdin);
		author_book.insert(make_pair(author, book));
		book_author.insert(make_pair( book,author));
		string press;
		cout << "请输入出版社:";
		cin >> press;
		rewind(stdin);
		press_book.insert(make_pair(press, book));
		book_press.insert(make_pair(book,press));
		string booktime;
		cout << "请输入出版时间:";
		cin >> booktime;
		rewind(stdin);
		time_book.insert(make_pair(booktime, book));
		book_time.insert(make_pair( book,booktime));
	}
	else
	{
		cout << "该书已被注册" << endl;
	}
}

void CManage_books::delete_books(string book)
{
	map<string,int>::iterator ite = books.begin();
	ite = books.find( book);
	if (ite != books.end())
	{
		while (1)
		{
			cout << "书籍ID：" << ite->first << "\t图书现存量" << ite->second << endl;
			int choice = -1;
			cout << "是否删除（1为删除，0为放弃）" << endl;
			cin >> choice;
			rewind(stdin);
			if (choice == 1)
			{
				books.erase(ite);

			}
			else if (choice == 0)
				choice = -1;
			else
				cout << "输入有误，请重新输入" << endl;
		}
	}
	else
	{
		cout << "书库中没有该书" << endl;
	}
}

void CManage_books::alter_books(string book)
{
	map<string,int>::iterator ite;
	ite = books.find( book);
	if (ite != books.end())
	{
		while (1)
		{
			cout << "书籍ID：" << ite->first << "\t图书现存量" << ite->second << endl;
			cout << "是否修改？（1为修改，0为放弃）" << endl;
			int choice = -1;
			cin >> choice;
			rewind(stdin);
			if (choice == 0)
			{
				choice = -1;
				break;
			}
			else if (choice == 1)
			{
				cout << "请输入新的ID" << endl;
				cin >> book;
				rewind(stdin);
				cout << "请输入新的ID" << endl;
				int num_book = ite->second;
				books.erase(ite);
				books.insert(pair<string,int>(book, num_book));
				break;
			}
			else
				cout << "输入有误，请从新输入" << endl;
		}
	}
}

CManage_books::~CManage_books()
{
}
