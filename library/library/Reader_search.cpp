#include "Reader_search.h"



CReader_search::CReader_search()
{
	while (1)
	{
		cout << "��<1>����������<2>ѧ������" << endl;
		int choice = -1;
		cin >> choice;
		rewind(stdin);
		if (choice == 1)
		{
			reader_search();
			break;
		}
		else if (choice == 2)
		{
			numberstudent_search();
			break;
		}
		else
			cout << "������������������" << endl;
	}
}



void CReader_search::numberstudent_search()
{
	cout << "������ѧ��:";
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	map<string, string>::iterator ite = id_reader.begin();
	ite = id_reader.find(id_student);
	cout << "��ѧ��Ϊ:" << ite->second << endl;
	ite = student_brrow.find(ite->second);
	if (ite != student_brrow.end())
	{
		cout << "��ѧ��������У�" << ite->second ;
	}
}


void CReader_search::reader_search()
{
	cout << "���������:";
	string reader = "\0";
	cin >> reader;
	rewind(stdin);
	map<string, string>::iterator ite = reader_id.begin();
	ite = id_reader.find(reader);
	cout << "��ѧ����ѧ��Ϊ:" << ite->second << endl;
	ite = student_brrow.find(reader);
	if (ite != student_brrow.end())
	{
		cout << "��ѧ��������У�" << ite->second;
	}
}


CReader_search::~CReader_search()
{
}
