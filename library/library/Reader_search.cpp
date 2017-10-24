#include "Reader_search.h"



CReader_search::CReader_search()
{
	//while (1)
	//{
	//	cout << "按<1>名字搜索，<2>学号搜索" << endl;
	//	int choice = -1;
	//	cin >> choice;
	//	//fflush(stdin);
	//	if (choice == 1)
	//	{
	//		reader_search();
	//		break;
	//	}
	//	else if (choice == 2)
	//	{
	//		numberstudent_search();
	//		break;
	//	}
	//	else
	//		cout << "输入有误！请重新输入" << endl;
	//}
}

void CReader_search::Reader_search()
{
	while (1)
	{
		cout << "按<1>名字搜索，<2>学号搜索" << endl;
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			cout << "输入有误！请重新输入" << endl;
	}
}

void CReader_search::numberstudent_search()
{
	cout << "请输入学号:";
	string id_student = "\0";
	cin >> id_student;
	//fflush(stdin);
	map<string, string>::iterator ite = id_reader.begin();
	ite = id_reader.find(id_student);
	cout << "该学生为:" << ite->second << endl;
	ite = student_brrow.find(ite->first);
	if (ite != student_brrow.end())
	{
		cout << "该学生借的书有：" << ite->second << endl;
	}
}


void CReader_search::reader_search()
{
	cout << "请输入读者:";
	string reader = "\0";
	cin >> reader;
	//fflush(stdin);
	map<string, string>::iterator ite = reader_id.begin();
	ite = reader_id.find(reader);
	cout << "该学生的学号为:" << ite->second << endl;
	ite = student_brrow.find(ite->second);
	if (ite != student_brrow.end())
	{
		cout << "该学生借的书编号有：" << ite->second <<endl;
	}
}


CReader_search::~CReader_search()
{
}
