#include "Brrow_books.h"
#include   <functional> 
#include   <algorithm> 


CBrrow_books::CBrrow_books()
{
	cout << "������ͼ����" << endl;
	cin >> id_book;
	map<string, int>::iterator ite = books.begin();
	ite = books.find(id_book);
	if (ite != books.end())
	{
		if (ite->second != 0)
		{
			cout << "���������ѧ��" << endl;
			cin >> num_student;
			rewind(stdin);
			brrow_student.insert(make_pair(num_student, ite->first));
			int num_books = ite->second;
			books.erase(ite);
			books.insert(pair<string,int>(id_book, ite->second - 1));
		}
		else
			cout << "�����ѱ����" << endl;
	}
}


CBrrow_books::~CBrrow_books()
{
}
