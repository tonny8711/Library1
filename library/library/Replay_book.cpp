#include "Replay_book.h"
#include   <functional> 
#include   <algorithm> 



CReplay_book::CReplay_book()
{
	string num_student = "\0";
	cout << "请输入你的学号" << endl;
	cin >> num_student;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	multimap<string, string>::iterator ite ;
	multimap<string, string>::iterator ite2 = brrow_student.begin();
	ite = student_brrow.find(num_student);
	if (ite != student_brrow.end())
	{
		ite2 = brrow_student.find(ite->second);
		string id_book;
		cout << "输入所借书籍的编号" << endl;
		cin >> id_book;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (1)
		{
			if (ite->second == id_book)
				break;
			else if (ite != ite2)
			{
				ite = brrow_student.find(num_student);
			}
			else
			{
				cout << "该学生没有借这本书" << endl;
				break;
			}
		}
		student_brrow.erase(ite);
		brrow_student.erase(ite2);
		cout << "该书已还" << endl;
	}
	else
		cout << "你没有借书记录" << endl;
}


CReplay_book::~CReplay_book()
{
}
