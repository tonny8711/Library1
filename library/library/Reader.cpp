#include "Reader.h"



CReader::CReader()
{
	cout << "<1>增加读者，<2>删除读者，<3>修改读者" << endl;
	int choice = -1;
	while (1)
	{
		cin >> choice;
		if (choice == 1)
		{
			create_reader();
			break;
		}
		else if (choice == 2)
		{
			delete_reader();
			break;
		}
		else if (choice == 3)
		{
			alter_reader();
			break;
		}
		else
			cout << "输入有误！，请重新输入" << endl;
	}
}

void CReader::create_reader()
{
	cout << "输入所增加读者的信息" << endl;
	cout << "学号:";
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	cout << "姓名:";
	string name_student = "\0";
	cin >> name_student;
	rewind(stdin);
	map<string, string>::iterator ite = id_reader.begin();
	ite = id_reader.find(id_student);
	if (ite == id_reader.end())
		cout << "该读者已被注册" << endl;
	else
	{
		pair<map<string, string>::iterator, bool> pite1 = id_reader.insert(pair<string, string>(id_student, name_student));
		pair<map<string, string>::iterator, bool> pite2 = reader_id.insert(pair<string, string>( name_student, id_student));
		if (pite1.second == false || pite2.second == false)
		{
			cout << "读者注册出现错误" << endl;
			exit(-1);
		}
	}
}

void CReader::delete_reader()
{
	cout << "*****删除读者*****" << endl;
	cout << "输入所要删除读者的学号" << endl;
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	map<string, string>::iterator ite1 = id_reader.begin();
	map<string, string>::iterator ite2= reader_id.begin();
	ite1 = id_reader.find(id_student);
	ite2 = reader_id.find(ite1->second);
	if (ite1 == id_reader.end())
	{
		cout << "该学号没有被注册" << endl;
	}
	else
	{
		while (1)
		{
			cout << "学号:" << ite1->first << "姓名:" << ite1->second << endl;
			cout << "是否要删除？（1为删除，0为放弃）" << endl;
			int choice = -1;
			if (choice == 1)
			{
				id_reader.erase(ite1);
				reader_id.erase(ite2);
				choice = -1;
				break;
			}
			else if (choice == 0)
			{
				choice = -1;
				break;
			}
			else
				cout << "输入有误，请重新输入" << endl;
		}
	}
}

void CReader::alter_reader()
{
	cout << "*****修改读者*****" << endl;
	cout << "输入所要修改读者的学号:" ;
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	map<string, string>::iterator ite1 = id_reader.begin();
	map<string, string>::iterator ite2 = reader_id.begin();
	ite1 = id_reader.find(id_student);
	if (ite1 == id_reader.end())
	{
		cout << "该学号没有被注册" << endl;
	}
	else
	{
		while (1)
		{
			cout << "学号:" << ite1->first << "姓名:" << ite1->second << endl;
			cout << "是否要修改？（1为修改，0为放弃）" << endl;
			int choice = -1;
			if (choice == 1)
			{
				string name_student = ite1->second;  
				ite2 = reader_id.find(name_student);
				id_reader.erase(ite1);
				reader_id.erase(ite2);
				choice = -1;
				cout << "请输入新的学号:";
				cin >> id_student;
				rewind(stdin);
				name_student = "\0";
				cout << "请输入新的姓名:";
				cin >> name_student;
				rewind(stdin);
				pair<map<string, string>::iterator, bool> pite = id_reader.insert(pair<string, string>(id_student, name_student));
				reader_id.insert(pair<string, string>(name_student, id_student));
				if (pite.second == false)
				{
					cout << "读者修改出现错误" << endl;
					exit(-1);
				}
				else
					break;
			}
			else if (choice == 0)
			{
				choice = -1;
				break;
			}
			else
				cout << "输入有误，请重新输入" << endl;
		}
	}
}


CReader::~CReader()
{
}
