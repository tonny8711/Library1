#include "iostream"
#include "map"
#include "string"


using namespace std;

void main()
{
	map<int, string > _map;
	_map[1] = "student_one";
	_map[2] = "student_two";
	_map[3] = "student_three";
	//_map[0] = "ZERO";
	//_map[1] = "ONE";
	//_map[2] = "TWO";
	//_map[3] = "THREE";
	//_map[4] = "FORE";
	//_map[5] = "FIVE";
	pair<map<int,string>::iterator,bool> pa = _map.insert(map<int, string>::value_type(1, "six"));
	if (pa.first == _map.begin())
		cout << "_map.begin" << endl;
	if (pa.first == _map.end())
		cout << "_map.end" << endl;
	if (pa.second)
		cout << "secceed" << endl;
	_map.insert(pair<int, string>(5, "six"));
	map<int, string>::iterator ite = _map.begin();
	//map<int, string>::iterator ite2 = _map.begin();
	ite = _map.find(3); 
	if(ite != _map.end())
	    cout << ite->first << "\t" << ite->second << endl;
	for (ite = _map.begin(); ite != _map.end(); ite++)
	{
		cout << ite->first << "\t" << ite->second << endl;
	}
	////cout << num << endl;
l