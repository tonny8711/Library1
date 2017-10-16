#include "Reader.h"



CReader::CReader()
{
	cout << "<1>���Ӷ��ߣ�<2>ɾ�����ߣ�<3>�޸Ķ���" << endl;
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
			cout << "�������󣡣�����������" << endl;
	}
}

void CReader::create_reader()
{
	cout << "���������Ӷ��ߵ���Ϣ" << endl;
	cout << "ѧ��:";
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	cout << "����:";
	string name_student = "\0";
	cin >> name_student;
	rewind(stdin);
	map<string, string>::iterator ite = id_reader.begin();
	ite = id_reader.find(id_student);
	if (ite == id_reader.end())
		cout << "�ö����ѱ�ע��" << endl;
	else
	{
		pair<map<string, string>::iterator, bool> pite1 = id_reader.insert(pair<string, string>(id_student, name_student));
		pair<map<string, string>::iterator, bool> pite2 = reader_id.insert(pair<string, string>( name_student, id_student));
		if (pite1.second == false || pite2.second == false)
		{
			cout << "����ע����ִ���" << endl;
			exit(-1);
		}
	}
}

void CReader::delete_reader()
{
	cout << "*****ɾ������*****" << endl;
	cout << "������Ҫɾ�����ߵ�ѧ��" << endl;
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	map<string, string>::iterator ite1 = id_reader.begin();
	map<string, string>::iterator ite2= reader_id.begin();
	ite1 = id_reader.find(id_student);
	ite2 = reader_id.find(ite1->second);
	if (ite1 == id_reader.end())
	{
		cout << "��ѧ��û�б�ע��" << endl;
	}
	else
	{
		while (1)
		{
			cout << "ѧ��:" << ite1->first << "����:" << ite1->second << endl;
			cout << "�Ƿ�Ҫɾ������1Ϊɾ����0Ϊ������" << endl;
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
				cout << "������������������" << endl;
		}
	}
}

void CReader::alter_reader()
{
	cout << "*****�޸Ķ���*****" << endl;
	cout << "������Ҫ�޸Ķ��ߵ�ѧ��:" ;
	string id_student = "\0";
	cin >> id_student;
	rewind(stdin);
	map<string, string>::iterator ite1 = id_reader.begin();
	map<string, string>::iterator ite2 = reader_id.begin();
	ite1 = id_reader.find(id_student);
	if (ite1 == id_reader.end())
	{
		cout << "��ѧ��û�б�ע��" << endl;
	}
	else
	{
		while (1)
		{
			cout << "ѧ��:" << ite1->first << "����:" << ite1->second << endl;
			cout << "�Ƿ�Ҫ�޸ģ���1Ϊ�޸ģ�0Ϊ������" << endl;
			int choice = -1;
			if (choice == 1)
			{
				string name_student = ite1->second;  
				ite2 = reader_id.find(name_student);
				id_reader.erase(ite1);
				reader_id.erase(ite2);
				choice = -1;
				cout << "�������µ�ѧ��:";
				cin >> id_student;
				rewind(stdin);
				name_student = "\0";
				cout << "�������µ�����:";
				cin >> name_student;
				rewind(stdin);
				pair<map<string, string>::iterator, bool> pite = id_reader.insert(pair<string, string>(id_student, name_student));
				reader_id.insert(pair<string, string>(name_student, id_student));
				if (pite.second == false)
				{
					cout << "�����޸ĳ��ִ���" << endl;
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
				cout << "������������������" << endl;
		}
	}
}


CReader::~CReader()
{
}
