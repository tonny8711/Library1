#include "Brrow_books.h"
#include   <functional> 
#include   <algorithm> 


CBrrow_books::CBrrow_books()
{
	cout << "������ͼ����" << endl;
	cin >> id_book;
	map<string, string>::iterator ite = ID_book.begin();
	ite = ID_book.find(id_book);
	if (ite != ID_book.end())
	{
		map<string, int>::iterator ite1 = books.find(ite->second);
		if (ite1 != books.end())
		{
			if (ite1->second != 0)
			{
				cout << "���������ѧ��" << endl;
				cin >> num_student;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				brrow_student.insert(make_pair(ite->first, num_student));
				student_brrow.insert(make_pair(num_student, ite->first));
				int num_books = ite1->second - 1;
				books.erase(ite1);
				if (num_books != 0)
					books.insert(pair<string, int>(ite->second, num_books));
			}
		}
		else
			cout << "�����ѱ����" << endl;
	}
	else
		cout << "�����û�и��飡" << endl;
}


CBrrow_books::~CBrrow_books()
{
}
