#pragma once
#include "Book_search.h"
#include "Reader_search.h"
class CReach:public CBook_search ,CReader_search
{
public:
	CReach();
	~CReach();
};

