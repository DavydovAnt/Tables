#pragma once
#include"THashTable.h"

#define TabHashStep 7

class TArrayHashTable : public THashTable {
protected:
	TTabRecord * pRecs;	
	int TabSize;		
	int HashStep;		
	int FreePos;		
	int CurrPos;		
	TTabRecord Mark;	
	TTabRecord Empty;	

	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }

public:
	TArrayHashTable(int size = TabMaxSize, int Step = TabHashStep);
	virtual ~TArrayHashTable();

	virtual bool IsFull() const { return DataCount >= TabSize; }

	virtual bool FindRecord(TKey k);			
	virtual int InsRecord(TKey k, TValue val);	
	virtual int DelRecord(TKey k);				

	virtual int Reset();				
	virtual int IsTabEnded() const;		
	virtual int GoNext();				

	virtual TKey GetKey()const;
	virtual TValue GetValue()const;
};