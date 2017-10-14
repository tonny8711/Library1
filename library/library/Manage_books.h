#include"set"
#include "map"
#include"string"
#define MAX_books 100;
using namespace std;
class CManage_books
{
public:
	CManage_books();
	void creat_books(string book);
	void delete_books(string book);
	void alter_books(string book);
	~CManage_books();
	string book;
	map<string,int>books;
};

