#pragma once
#include "TTable.h"
enum TDataPos{FIRST_POS, CURRENT_POS, LAST_POS};

class TArrayTable : public TTable {
protected:
	TTabRecord *pRecs;	
	int TabSize;		
	int CurrPos;		

public:
	TArrayTable(int size = TabMaxSize) {
		pRecs = new TTabRecord[size];
		TabSize = size;
		DataCount = CurrPos = 0;
	}
	~TArrayTable() {
		delete[]pRecs;
	}
	virtual bool IsFull() const { return DataCount >= TabSize; }
	int GetTabSize()const { return TabSize; }
	virtual TKey GetKey() const { return GetKey(CURRENT_POS); }
	virtual TValue GetValue() const { return GetValue(CURRENT_POS); }
	virtual TKey GetKey(TDataPos mode) const;
	virtual TValue GetValue(TDataPos mode) const;
	TTabRecord Get_pRec(int i) const { return pRecs[i]; }
	virtual int Reset();				
	virtual int IsTabEnded() const;		
	virtual int GoNext();				
	virtual int SetCurrentPos(int pos);	
	int GetCurrentPos() const { return CurrPos; }

	friend class TSortTable;
};
