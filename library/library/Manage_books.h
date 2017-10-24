#pragma once
#include"set"
#include "map"
#include"string"
#include "Books.h"
#define MAX_books 100;
class CManage_books :public CBooks
{
public:
	CManage_books();
	void creat_books(string book);
	void delete_books(string book);
	void alter_books(string book);
	~CManage_books();
private:
	string book;
};

