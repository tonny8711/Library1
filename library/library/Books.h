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
	static multimap<string, string>brrow_student; //借的书，学生
	static multimap<string, string>student_brrow;
	static map<string, string> id_reader;//学号，姓名
	static map<string, string> reader_id;
	static map<string, int>books;//书名，剩余
	static map<string, string>ID_book;//书号，书名
	static map<string, string>book_ID;
	//map<>
	static map<string, string>author_book;//作者，书名
	static map<string, string>book_author;
	static map<string, string>press_book;//出版社，书名
	static map<string, string>book_press;
	static map<string, string>time_book;//出版时间，书名
	static map<string, string>book_time;
};

