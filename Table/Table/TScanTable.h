#pragma once
#include "TArrayTable.h"
class TScanTable:public TArrayTable
{
public:
	TScanTable(int size = TabMaxSize) :TArrayTable(size) {};

	virtual bool FindRecord(TKey k);			
	virtual int InsRecord(TKey k, TValue pVal);	
	virtual int DelRecord(TKey k);				

};

