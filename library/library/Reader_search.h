#pragma once
#include "Books.h"
class CReader_search :
	public CBooks
{
public:
	CReader_search();
	~CReader_search();
	void numberstudent_search();
	void reader_search();
private:
	multimap<string, string>::iterator ite;
};

