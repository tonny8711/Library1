#pragma once
#include "Books.h"
class CReader :
	public CBooks
{
public:
	CReader();
	~CReader();
	void create_reader();
	void delete_reader();
	void alter_reader();
};

