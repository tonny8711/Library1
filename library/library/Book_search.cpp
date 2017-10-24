#include "Book_search.h"



CBook_search::CBook_search()
{
	while (1)
	{
		cout << "按<1>书名搜索，<2>书号搜索，<3>作者搜索，<4>出版社搜索，<5>出版时间搜索" << endl;
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
			cout << "输入有误，请重新输入！" << endl;
	}
}


void CBook_search::name_search()
{
	string name_book = "\0";
	cout << "请输入书名:";
	cin >> name_book;
	//fflush(stdin);
	ite_book = book_ID.find(name_book);
	if (ite_book != book_ID.end())
	{
		cout << "该书书号:" << ite_book->second << endl;
		book_ite = book_author.find(name_book);
		cout << "该书作者:" << book_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "该书出版社:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "该书出版时间:" << book_ite->second << endl;
	}
}

void CBook_search::number_search()
{
	string num_book = 0;
	cout << "请输入书号:";
	cin >> num_book;
	//fflush(stdin);
	ite_number = ID_book.find(num_book);
	if (ite_number != ID_book.end())
	{
		cout << "该书书名:" << ite_number->second << endl;
		string name_book = ite_number->second;
		book_ite = book_author.find(name_book);
		cout << "该书作者:" << book_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "该书出版社:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "该书出版时间:" << book_ite->second << endl;
	}
	else
		cout << "此书籍不存在" << endl;
}

void CBook_search::author_search()
{
	string author = "\0";
	cout << "请输入作者:";
	cin >> author;
	//fflush(stdin);
	ite_author = author_book.find(author);
	if (ite_author != author_book.end())
	{
		cout << "该书书名:" << ite_author->second << endl;
		string name_book = ite_author->second;
		num_ite = book_ID.find(name_book);
		cout << "该书书号:" << num_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "该书出版社:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "该书出版时间:" << book_ite->second << endl;
	}
	else
		cout << "此书籍不存在" << endl;
}

void CBook_search::press_search()
{
	string press = "\0";
	cout << "请输入出版社:";
	cin >> press;
	//fflush(stdin);
	ite_press = press_book.find(press);
	if (ite_press != press_book.end())
	{
		cout << "该书书名:" << ite_press->second << endl;
		string name_book = ite_press->second;
		num_ite = book_ID.find(name_book);
		cout << "该书书号:" << num_ite->second << endl;
		book_ite = book_author.find(name_book);
		cout << "该书作者:" << book_ite->second << endl;
		book_ite = book_time.find(name_book);
		cout << "该书出版时间:" << book_ite->second << endl;
	}
	else
		cout << "此书籍不存在" << endl;
}

void CBook_search::booktime_search() 
{
	string booktime = "\0";
	cout << "请输入出版时间:";
	cin >> booktime;
	//fflush(stdin);
	ite_time = time_book.find(booktime);
	if (ite_time != time_book.end())
	{
		cout << "该书书名:" << ite_time->second << endl;
		string name_book = ite_time->second;
		num_ite = book_ID.find(name_book);
		cout << "该书书号:" << num_ite->second << endl;
		book_ite = book_press.find(name_book);
		cout << "该书出版社:" << book_ite->second << endl;
		book_ite = book_author.find(name_book);
		cout << "该书作者:" << book_ite->second << endl;
	}
	else
		cout << "此书籍不存在" << endl;
}

CBook_search::~CBook_search()
{
}
