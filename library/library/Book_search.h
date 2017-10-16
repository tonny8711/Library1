#pragma once
#include "Books.h"
class CBook_search :
	public CBooks
{
public:
	CBook_search();
	~CBook_search();
	void name_search();
	void number_search();
	void author_search();
	void press_search();
	void booktime_search();
private:
	map<string, string>::iterator ite_book = book_ID.begin();
	map<string, string>::iterator ite_number = ID_book.begin();
	map<string, string>::iterator ite_author = author_book.begin();
	map<string, string>::iterator ite_press = press_book.begin();
	map<string, string>::iterator ite_time = time_book.begin();
	map<string, string>::iterator book_ite;
	map<string, string>::iterator num_ite;
};

