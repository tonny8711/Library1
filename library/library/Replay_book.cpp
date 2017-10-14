#include "Replay_book.h"



CReplay_book::CReplay_book()
{
	num_student = "\0";
	cout << "请输入你的学号" << endl;
	cin >> num_student;
	rewind(stdin);
	multimap<string, string>::iterator ite = brrow_student.begin;
	multimap<string, string>::iterator ite2 = brrow_student.end;
	ite = find(brrow_student.begin, brrow_student.end, num_student);
	if (ite != brrow_student.end)
	{
		cout << "输入所借书籍的编号" << endl;
		cin >> id_book;
		rewind(stdin);
		while (1)
		{
			if (ite->second == id_book)
				break;
			else if (ite != ite2)
			{
				ite = find(ite, ite2, num_student);
			}
			else
			{
				cout << "该学生没有借这本书" << endl;
				break;
			}
		}
		brrow_student.erase(ite);
		cout << "该书已还" << endl;
	}
	else
		cout << "你没有借书记录" << endl;
}


CReplay_book::~CReplay_book()
{
}
