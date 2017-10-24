#include "Manage_books.h"
#include "iostream"
#include   <functional> 
#include   <algorithm> 




CManage_books::CManage_books()
{
	cout << "����鼮����1\tɾ���鼮����2\t�޸��鼮����3" << endl;
	int import_num = 0;
	cin >> import_num;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		if (import_num != 1 && import_num != 2 && import_num != 3)
		{
			cout << "������������������" << endl;
			cin >> import_num;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
		cout << "����������:";
		cin >> book;
		delete_books(book);
		book = "\0";
	}
	if (import_num == 3)
	{
		cout << "����������:";
		cin >> book;
		alter_books(book);
		book = "\0";
	}
}

void CManage_books::creat_books(string book)
{
	if (books.find( book) == books.end())
	{
		books.insert(pair<string, int>(book, 1));
		string num_book = "\0";
		cout << "���������:";
		cin >> num_book;
		//fflush(stdin);
		book_ID.insert(make_pair(book, num_book));
		ID_book.insert(make_pair( num_book, book));
		string author;
		cout << "����������:";
		cin >> author;
		//fflush(stdin);
		author_book.insert(make_pair(author, book));
		book_author.insert(make_pair( book,author));
		string press;
		cout << "�����������:";
		cin >> press;
		//fflush(stdin);
		press_book.insert(make_pair(press, book));
		book_press.insert(make_pair(book,press));
		string booktime;
		cout << "���������ʱ��:";
		cin >> booktime;
		//fflush(stdin);
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
	multimap<string, string>::iterator ite2 = student_brrow.begin();
	map<string, int>::iterator ite3 = books.begin();//������ʣ��
	map<string, string>::iterator ite4 = ID_book.begin();//��ţ�����
	map<string, string>::iterator ite5 = book_ID.begin();
	map<string, string>::iterator ite6 = author_book.begin();//���ߣ�����
	map<string, string>::iterator ite7 = book_author.begin();
	map<string, string>::iterator ite8 = press_book.begin();//�����磬����
	map<string, string>::iterator ite9 = book_press.begin();
	map<string, string>::iterator ite10 = time_book.begin();//����ʱ�䣬����
	map<string, string>::iterator ite11 = book_time.begin();
	ite = books.find( book);
	
	if (ite != books.end())
	{
		while (1)
		{
			ite2 = student_brrow.find(ite ->first);
			ite5 = book_ID.find(ite->first);
			ite4 = ID_book.find(ite5->second);
			ite7 = book_author.find(ite->first);
			ite6 = author_book.find(ite7->second);
			ite9 = book_press.find(ite ->first);
			ite8 = press_book.find(ite9 ->second);
			ite11 = book_time.find(ite->first);
			ite10 = time_book.find(ite11->second);
			cout << "�鼮ID��" << ite->first << "\tͼ���ִ���" << ite->second << endl;
			int choice = -1;
			cout << "�Ƿ�ɾ����1Ϊɾ����0Ϊ������" << endl;
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 1)
			{
				books.erase(ite);
				book_ID.erase(ite5);
				ID_book.erase(ite4);
				book_author.erase(ite7);
				author_book.erase(ite6);
				book_press.erase(ite9);
				press_book.erase(ite8);
				book_time.erase(ite11);
				time_book.erase(ite10);
				break;

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
	map<string, int>::iterator ite = books.begin();
	multimap<string, string>::iterator ite2 = student_brrow.begin();
	map<string, int>::iterator ite3 = books.begin();//������ʣ��
	map<string, string>::iterator ite4 = ID_book.begin();//��ţ�����
	map<string, string>::iterator ite5 = book_ID.begin();
	map<string, string>::iterator ite6 = author_book.begin();//���ߣ�����
	map<string, string>::iterator ite7 = book_author.begin();
	map<string, string>::iterator ite8 = press_book.begin();//�����磬����
	map<string, string>::iterator ite9 = book_press.begin();
	map<string, string>::iterator ite10 = time_book.begin();//����ʱ�䣬����
	map<string, string>::iterator ite11 = book_time.begin();
	ite = books.find( book);
	if (ite != books.end())
	{
		while (1)
		{
			ite2 = student_brrow.find(ite->first);
			ite5 = book_ID.find(ite->first);
			ite4 = ID_book.find(ite5->second);
			ite7 = book_author.find(ite->first);
			ite6 = author_book.find(ite7->second);
			ite9 = book_press.find(ite->first);
			ite8 = press_book.find(ite9->second);
			ite11 = book_time.find(ite->first);
			ite10 = time_book.find(ite11->second);
			cout << "�鼮��" << ite->first << "\tͼ���ִ���" << ite->second << endl;
			cout << "�Ƿ��޸ģ���1Ϊ�޸ģ�0Ϊ������" << endl;
			int choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 0)
			{
				choice = -1;
				break;
			}
			else if (choice == 1)
			{
				string bookid = "\0";
				cout << "�������µ�ID" << endl;
				cin >> bookid;
				//fflush(stdin);
				//cout << "�������µ�ID" << endl;
				//int num_book = ite->second;
				int num_book = 1;
				books.erase(ite);
				book_ID.erase(ite5);
				ID_book.erase(ite4);
				//ID_book.erase(ite);
				books.insert(pair<string,int>(book, num_book));
				book_ID.insert(pair<string, string>(book, bookid));
				ID_book.insert(pair<string, string>(book, bookid));
				break;
			}
			else
				cout << "�����������������" << endl;
		}

	}
	else
		cout << "�����û�и���" << endl;
}

CManage_books::~CManage_books()
{
}
