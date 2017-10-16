#include"string"
#include "iostream"
#include"Manage_books.h"
#include "Books.h"
using namespace std;
class CBrrow_books :public CBooks
{
public:
	CBrrow_books();
	~CBrrow_books();
	string id_book = "\0";
	string num_student = "\0";
	
};

