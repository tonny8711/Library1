#pragma once
#include"map"
#include"iostream"
#include "string"
using namespace std;
class CBooks
{
public:
	CBooks();
	~CBooks();
	static multimap<string, string>brrow_student; //����飬ѧ��
	static multimap<string, string>student_brrow;
	static map<string, string> id_reader;//ѧ�ţ�����
	static map<string, string> reader_id;
	static map<string, int>books;//������ʣ��
	static map<string, string>ID_book;//��ţ�����
	static map<string, string>book_ID;
	//map<>
	static map<string, string>author_book;//���ߣ�����
	static map<string, string>book_author;
	static map<string, string>press_book;//�����磬����
	static map<string, string>book_press;
	static map<string, string>time_book;//����ʱ�䣬����
	static map<string, string>book_time;
};

