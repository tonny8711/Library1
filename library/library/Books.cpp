#include "Books.h"
#include "fstream"
#include "iostream"
using namespace std;

multimap<string, string> CBooks::brrow_student; //书的编号,学生学号
multimap<string, string> CBooks::student_brrow;
map<string, string> CBooks::id_reader;//学号，姓名
map<string, string> CBooks::reader_id;
map<string, int> CBooks::books;//书名，剩余
map<string, string> CBooks::ID_book;//书号，书名
map<string, string> CBooks::book_ID;
//map<>
map<string, string> CBooks::author_book;//作者，书名
map<string, string> CBooks::book_author;
map<string, string> CBooks::press_book;//出版社，书名
map<string, string> CBooks::book_press;
map<string, string> CBooks::time_book;//出版时间，书名
map<string, string> CBooks::book_time;


void CBooks::readfile()
{
	ifstream iofilebookid_studentid("bookid_studentid.txt");
	multimap<string, string>::iterator ite;
	string bookid = "\0";
	string bookname = "\0";
	string studentid = "\0";
	string studentname = "\0";
	string author = "\0";
	string press = "\0";
	string booktime = "\0";
	int num_book = 0;
	iofilebookid_studentid >> bookid >> studentid;
	while (1)
	{
		if (bookid != "\0" && studentid != "\0")
		{
			brrow_student.insert(pair<string, string>(bookid, studentid));
			bookid = "\0";
			studentid = "\0";
			iofilebookid_studentid >> bookid >> studentid;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofilestudentid_bookid("student_bookid.txt");
	iofilestudentid_bookid >> studentid >> bookid;
	while (1)
	{
		if (bookid != "\0" && studentid != "\0")
		{
			student_brrow.insert(pair<string, string>(studentid, bookid));
			bookid = "\0";
			studentid != "\0";
			iofilestudentid_bookid >> studentid >> bookid;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofilestudentid_name("studentid_name.txt");
	iofilestudentid_name >> studentid >> studentname;
	while (1)
	{
		if (studentname != "\0"&& studentid != "\0")
		{
			id_reader.insert(pair<string, string>(studentid,studentname));
			studentname = "\0";
			studentid = "\0";
			iofilestudentid_name >> studentid >> studentname;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofilestudentname_id("studentname_id.txt");
	iofilestudentname_id >> studentname >> studentid;
	while (1)
	{
		if (studentname != "\0" && studentid != "\0")
		{
			reader_id.insert(pair<string, string>(studentname, studentid));
			studentname = "\0";
			studentid = "\0";
			iofilestudentname_id>> studentname >> studentid;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream infilbook_num("bookname_number.txt");
	infilbook_num >> bookname >> num_book;
	while (1)
	{
		if (bookname != "\0" && num_book != 0)
		{
			books.insert(pair<string, int>(bookname, num_book));
			bookname = "\0";
			num_book = 0;
			infilbook_num >> bookname >> num_book;
		}
		else
			break;
	}
	ifstream iofilebookid_name("bookid_name.txt");
	bookid = "\0";
	bookname = "\0";
	iofilebookid_name >> bookid >> bookname;
	while (1)
	{
		if (bookname != "\0" && bookid != "\0")
		{
			ID_book.insert(pair<string, string>(bookid, bookname));
			bookid = "\0";
			bookname = "\0";
			iofilebookid_name >> bookid >> bookname;
		}
		else
			break;
	}
	ifstream iofilebookname_id("bookname_id.txt");
	bookid = "\0";
	bookname = "\0";
	iofilebookname_id >> bookname >> bookid;
	while (1)
	{
		if (bookname != "\0" && bookid != "\0")
		{
			book_ID.insert(pair<string, string>(bookname, bookid));
			bookid = "\0";
			bookname = "\0";
			iofilebookname_id >> bookname >> bookid;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofileauthor_bookname("author_bookname.txt");
	bookname = "\0";
	iofileauthor_bookname >> author >> bookname;
	while (1)
	{
		if (bookname != "\0" && author != "\0")
		{
			author_book.insert(pair<string, string>(author , bookname));
			bookname = "\0";
			author = "\0";
			iofileauthor_bookname >> author >> bookname;
		}
		else
			break;
	}
	ifstream iofilebookname_author("bookname_author.txt");
	author = "\0";
	bookname = "\0";
	iofilebookname_author >> bookname >> author;
	while (1)
	{
		if (bookname != "\0" && author != "\0")
		{
			book_author.insert(pair<string, string>(bookname, author));
			author = "\0";
			bookname = "\0";
			iofilebookname_author >> bookname >> author;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofilebookname_press("bookname_press.txt");
	bookname = "\0";
	iofilebookname_press  >> bookname >> press;
	while (1)
	{
		if (bookname != "\0" && press != "\0")
		{
			book_press.insert(pair<string, string>(bookname, press));
			bookname = "\0";
			press = "\0";
			iofilebookname_press >> bookname>> press;
		}
		else
			break;
	}
	ifstream iofilepress_bookname("press_bookname.txt");
	bookname = "\0";
	press = "\0";
	iofilepress_bookname >> press >> bookname;
	while (1)
	{
		if (bookname != "\0" && press != "\0")
		{
			press_book.insert(pair<string, string>(press, bookname));
			bookname = "\0";
			press = "\0";
			iofilepress_bookname >> press >> bookname;
		}
		else
			break;
	}
	bookid = "\0";
	bookname = "\0";
	studentid = "\0";
	studentname = "\0";
	author = "\0";
	press = "\0";
	booktime = "\0";
	num_book = 0;
	ifstream iofilebookname_time("bookname_time.txt");
	bookname = "\0";
	iofilebookname_time >> bookname >> booktime;
	while (1)
	{
		if (bookname != "\0" && booktime != "\0")
		{
			book_time.insert(pair<string, string>(bookname, booktime));
			bookname = "\0";
			booktime = "\0";
			iofilebookname_time >> bookname >> booktime;
		}
		else
			break;
	}
	ifstream iofilebooktime_name("booktime_name.txt");
	bookname = "\0";
	booktime = "\0";
	iofilebooktime_name >> booktime >> bookname;
	while (1)
	{
		if (bookname != "\0" && booktime != "\0")
		{
			time_book.insert(pair<string, string>(booktime, bookname));
			bookname = "\0";
			booktime = "\0";
			iofilebooktime_name >> booktime >> bookname;
		}
		else
			break;
	}
}


void CBooks::writefile()
{
	ofstream outfilebookid_studentid("bookid_studentid.txt");
	multimap<string, string>::iterator ite;
	string bookid = "\0";
	string bookname = "\0";
	string studentid = "\0";
	string studentname = "\0";
	string author = "\0";
	string press = "\0";
	string booktime = "\0";
	int num_book = 0;
	ite = brrow_student.begin();
	while (1)
	{
		if (ite != brrow_student.end())
		{
			bookid = ite->first;
			studentid = ite->second;
			outfilebookid_studentid << bookid << "\n" << studentid << "\n";
			ite++;
		}
		else
			break;
	}
	ofstream outfilestudentid_bookid("student_bookid.txt");
	ite = student_brrow.begin();
	while (1)
	{
		if (ite != student_brrow.end())
		{
			bookid = ite->second;
			studentid = ite->first;
			ite++;
			outfilestudentid_bookid << studentid << "\n" << bookid << "\n";
		}
		else
			break;
	}
	ofstream outfilestudentid_name("studentid_name.txt");
	ite = id_reader.begin();
	while (1)
	{
		if (ite != id_reader.end())
		{
			studentid = ite->first;
			studentname = ite->second;
			ite++;
			outfilestudentid_name << studentid << "\n" << studentname << "\n";
		}
		else
			break;
	}
	ofstream outfilestudentname_id("studentname_id.txt");
	ite = reader_id.begin();
	while (1)
	{
		if (ite != reader_id.end())
		{
			studentname = ite->first;
			studentid = ite->second;
			outfilestudentname_id << studentname << "\n" << studentid << "\n";
			ite++;
		}
		else
			break;
	}
	ofstream infilbook_num("bookname_number.txt");
	map<string, int>::iterator ite1 = books.begin();
	while (1)
	{
		if (ite1 != books.end())
		{
			bookname = ite1->first;
			num_book = ite1->second;
			ite1++;
			infilbook_num << bookname << "\n" << num_book << "\n";
		}
		else
			break;
	}
	ofstream outfilebookid_name("bookid_name.txt");
	bookid = "\0";
	bookname = "\0";
	ite = ID_book.begin();
	while (1)
	{
		if (ite != ID_book.end())
		{
			bookid = ite->first;
			bookname = ite->second;
			ite++;
			outfilebookid_name << bookid << "\n" << bookname << "\n";
		}
		else
			break;
	}
	ofstream outfilebookname_id("bookname_id.txt");
	bookid = "\0";
	bookname = "\0";
	ite = book_ID.begin();
	while (1)
	{
		if (ite != book_ID.end())
		{
			bookname = ite->first;
			bookid = ite->second;
			ite++;
			outfilebookname_id << bookname << "\n" << bookid << "\n";
		}
		else
			break;
	}
	ofstream outfileauthor_bookname("author_bookname.txt");
	bookname = "\0";
	ite = author_book.begin();
	while (1)
	{
		if (ite != author_book.end())
		{
			author = ite->first;
			bookname = ite->second;
			ite++;
			outfileauthor_bookname << author << "\n" << bookname << "\n";
		}
		else
			break;
	}
	ofstream outfilebookname_author("bookname_author.txt");
	author = "\0";
	bookname = "\0";
	ite = book_author.begin();
	while (1)
	{
		if (ite != book_author.end())
		{
			bookname = ite->first;
			author = ite->second;
			ite++;
			outfilebookname_author << bookname << "\n" << author << "\n";
		}
		else
			break;
	}
	ofstream outfilebookname_press("bookname_press.txt");
	if (!outfilebookname_press)
		cout << "错误 ！" << endl;
	bookname = "\0";
	ite = book_press.begin();
	while (1)
	{
		if (ite != book_press.end())
		{
			bookname = ite->first;
			press = ite->second;
			ite++;
			outfilebookname_press << bookname << "\n" << press << "\n";
		}
		else
			break;
	}
	/*ofstream outfilebookname_press("bookname_press.txt");
	bookname = "\0";
	press = "\0";
	ite = author_book.begin();
	while (1)
	{
		if (ite != author_book.end())
		{
			press = ite->first;
			bookname = ite->second;
			ite++;
			outfileauthor_bookname << press << bookname;
		}
		else
			break;
	}*/
	ofstream outfilepress_bookname("press_bookname.txt");
	bookname = "\0";
	press = "\0";
	ite = press_book.begin();
	while (1)
	{
		if (ite != press_book.end())
		{
			press = ite->first;
			bookname = ite->second;
			ite++;
			outfilepress_bookname << press << "\n" << bookname << "\n";
		}
		else
			break;
	}
	ofstream outfilebookname_time("bookname_time.txt");
	bookname = "\0";
	ite = book_time.begin();
	while (1)
	{
		if (ite != book_time.end())
		{
			bookname = ite->first;
			booktime = ite->second;
			ite++;
			outfilebookname_time << bookname << "\n" << booktime << "\n";
		}
		else
			break;
	}
	ofstream outfilebooktime_name("booktime_name.txt");
	bookname = "\0";
	booktime = "\0";
	ite = time_book.begin();
	while (1)
	{
		if (ite != time_book.end())
		{
			booktime = ite->first;
			bookname = ite->second;
			ite++;
			outfilebooktime_name << booktime << "\n" << bookname << "\n";
		}
		else
			break;
	}


}

void CBooks::getbooks()
{
	cout << "书名\t\t" << "编号\t\t" << "作者\t\t" << "出版社\t\t" << "出版时间\t\t" << endl;
	map<string, string>::iterator ite,ite_author,ite_press,ite_time;
	ite = book_ID.begin();
	ite_author = book_author.begin();
	ite_press = book_press.begin();
	ite_time = book_time.begin();
	while (1)
	{
		if (ite != book_ID.end())
		{
			cout << ite->first << "\t\t" << ite->second << "\t\t" << ite_author->second << "\t\t" << ite_press->second << "\t\t" << ite_time->second << endl;
			ite++;
			ite_author++;
			ite_press++;
			ite_time++;
		}
		else
			break;
	}
}
void CBooks::getreader()
{
	cout << "学生\t\t" << "学号\t\t" << endl;
	map<string, string>::iterator ite;
	ite = reader_id.begin();
	while (1)
	{
		if (ite != reader_id.end())
		{
			cout << ite->first << "\t\t" << ite->second << endl;
			ite++;
		}
		else
			break;
	}

}


void CBooks::student_brrowbook()
{
	cout << "学生学号\t" << "借的书的编号\t\t" << endl;
	map<string, string>::iterator ite;
	ite = brrow_student.begin();
	while (1)
	{
		if (ite != brrow_student.end())
		{
			cout << ite->first << "\t\t" << ite->second << endl;
			ite++;
		}
		else
			break;
	}
}



CBooks::CBooks()
{

}


CBooks::~CBooks()
{

}
