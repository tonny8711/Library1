#include "Manage_books.h"
#include "iostream"
#include   <functional> 
#include   <algorithm> 




CManage_books::CManage_books()
{
	cout << "����鼮����1\tɾ���鼮����2\t�޸��鼮����3" << endl;
	int import_num = 0;
	cin >> import_num;
	rewind(stdin);
	while (1)
	{
		if (import_num != 1 || import_num != 2 || import_num != 3)
		{
			cout << "������������������" << endl;
			cin >> import_num;
		}
		else
			break;
	}
	if (import_num == 1)
	{
		cout << "����������:";
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
		cout << "���������:";
		cin >> num_book;
		rewind(stdin);
		book_ID.insert(make_pair(book, num_book));
		ID_book.insert(make_pair( num_book, book));
		string author;
		cout << "����������:";
		cin >> author;
		rewind(stdin);
		author_book.insert(make_pair(author, book));
		book_author.insert(make_pair( book,author));
		string press;
		cout << "�����������:";
		cin >> press;
		rewind(stdin);
		press_book.insert(make_pair(press, book));
		book_press.insert(make_pair(book,press));
		string booktime;
		cout << "���������ʱ��:";
		cin >> booktime;
		rewind(stdin);
		time_book.insert(make_pair(booktime, book));
		book_time.insert(make_pair( book,booktime));
	}
	else
	{
		cout << "�����ѱ�ע��" << endl;
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
			cout << "�鼮ID��" << ite->first << "\tͼ���ִ���" << ite->second << endl;
			int choice = -1;
			cout << "�Ƿ�ɾ����1Ϊɾ����0Ϊ������" << endl;
			cin >> choice;
			rewind(stdin);
			if (choice == 1)
			{
				books.erase(ite);

			}
			else if (choice == 0)
				choice = -1;
			else
				cout << "������������������" << endl;
		}
	}
	else
	{
		cout << "�����û�и���" << endl;
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
			cout << "�鼮ID��" << ite->first << "\tͼ���ִ���" << ite->second << endl;
			cout << "�Ƿ��޸ģ���1Ϊ�޸ģ�0Ϊ������" << endl;
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
				cout << "�������µ�ID" << endl;
				cin >> book;
				rewind(stdin);
				cout << "�������µ�ID" << endl;
				int num_book = ite->second;
				books.erase(ite);
				books.insert(pair<string,int>(book, num_book));
				break;
			}
			else
				cout << "�����������������" << endl;
		}
	}
}

CManage_books::~CManage_books()
{
}
