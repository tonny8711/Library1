#include "Replay_book.h"



CReplay_book::CReplay_book()
{
	num_student = "\0";
	cout << "���������ѧ��" << endl;
	cin >> num_student;
	rewind(stdin);
	multimap<string, string>::iterator ite = brrow_student.begin;
	multimap<string, string>::iterator ite2 = brrow_student.end;
	ite = find(brrow_student.begin, brrow_student.end, num_student);
	if (ite != brrow_student.end)
	{
		cout << "���������鼮�ı��" << endl;
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
				cout << "��ѧ��û�н��Ȿ��" << endl;
				break;
			}
		}
		brrow_student.erase(ite);
		cout << "�����ѻ�" << endl;
	}
	else
		cout << "��û�н����¼" << endl;
}


CReplay_book::~CReplay_book()
{
}
