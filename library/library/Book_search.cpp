#include "Book_search.h"



CBook_search::CBook_search()
{
	while (1)
	{
		cout << "��<1>����������<2>���������<3>����������<4>������������<5>����ʱ������" << endl;
		int choice = -1;
		cin >> choice;
		//fflush(stdin);
		if (choice == 1)
		{
			name_search(); 
			break;
		}
		else if (choice == 2)
		{
			number_search();
			break;
		}
		else if (choice == 3)
		{
			author_search();
			break;
		}
		else if (choice == 4)
		{
			press_search();
			break;
		}
		else if (choice == 5)
		{
			booktime_search();
			break;
		}
		else
			cout << "�����������������룡" << endl;
	}
}


void CBook_search::name_search()
{
	string name_book = "\0";
	cout << "����������:";
	cin >> name_book;
	//fflush(stdin);
	ite_book = book_ID.find(name_book);
	if (ite_book != book_ID.end())
	{
		cout << "�������:" << ite_book->second << endl;
		book_ite = book_author.find(name_book);
		cout << "��������:" << book_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "���������:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "�������ʱ��:" << book_ite->second << endl;
	}
}

void CBook_search::number_search()
{
	string num_book = 0;
	cout << "���������:";
	cin >> num_book;
	//fflush(stdin);
	ite_number = ID_book.find(num_book);
	if (ite_number != ID_book.end())
	{
		cout << "��������:" << ite_number->second << endl;
		string name_book = ite_number->second;
		book_ite = book_author.find(name_book);
		cout << "��������:" << book_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "���������:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "�������ʱ��:" << book_ite->second << endl;
	}
	else
		cout << "���鼮������" << endl;
}

void CBook_search::author_search()
{
	string author = "\0";
	cout << "����������:";
	cin >> author;
	//fflush(stdin);
	ite_author = author_book.find(author);
	if (ite_author != author_book.end())
	{
		cout << "��������:" << ite_author->second << endl;
		string name_book = ite_author->second;
		num_ite = book_ID.find(name_book);
		cout << "�������:" << num_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "���������:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "�������ʱ��:" << book_ite->second << endl;
	}
	else
		cout << "���鼮������" << endl;
}

void CBook_search::press_search()
{
	string press = "\0";
	cout << "�����������:";
	cin >> press;
	//fflush(stdin);
	ite_press = press_book.find(press);
	if (ite_press != press_book.end())
	{
		cout << "��������:" << ite_press->second << endl;
		string name_book = ite_press->second;
		num_ite = book_ID.find(name_book);
		cout << "�������:" << num_ite->second << endl;
		book_ite = book_author.find(name_book);
		cout << "��������:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "�������ʱ��:" << book_ite->second << endl;
	}
	else
		cout << "���鼮������" << endl;
}

void CBook_search::booktime_search() 
{
	string booktime = "\0";
	cout << "���������ʱ��:";
	cin >> booktime;
	//fflush(stdin);
	ite_time = time_book.find(booktime);
	if (ite_time != time_book.end())
	{
		cout << "��������:" << ite_time->second << endl;
		string name_book = ite_time->second;
		num_ite = book_ID.find(name_book);
		cout << "�������:" << num_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "���������:" << book_ite->second << endl;
		book_ite = book_author.find(name_book);
		cout << "��������:" << book_ite->second << endl;
	}
	else
		cout << "���鼮������" << endl;
}

CBook_search::~CBook_search()
{
}
