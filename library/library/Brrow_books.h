#include"string"
#include "iostream"
#include"Manage_books.h"
using namespace std;
class CBrrow_books:public CManage_books
{
public:
	CBrrow_books();
	~CBrrow_books();
	string id_book = "\0";
	string num_student = "\0";
	multimap<string, string>brrow_student;
};

