#pragma once
#include <iostream>
#include "Record.h"

#define TabOK 0			//������ ���
#define TabEmpty -101	//������� �����
#define TabFull  -102	//������� �����
#define TabNoRec -103	//��� ������
#define TabRecDbl -104	//������������ ������
#define TabNoMem -105	//��� ������

#define TabMaxSize 25

class TTable {
protected:
	int DataCount;		//���������� ������� � �������
	int Efficiency;		//���������� ������������� ���������� �������� ���������� ��������
public:
	TTable() { DataCount = 0; Efficiency = 0; }
	virtual ~TTable() {};

	int GetDataCount() const { return DataCount; }
	int GetEfficiency() const { return Efficiency; }
	void ClearEfficiency() { Efficiency = 0; }
	bool IsEmpty() const { return DataCount == 0; }	
	virtual bool IsFull() const = 0;					

	virtual bool FindRecord(TKey k) = 0;			
	virtual int InsRecord(TKey k, TValue val) = 0;	
	virtual int DelRecord(TKey k) = 0;				

	virtual int Reset() = 0;
	virtual int IsTabEnded() const = 0;
	virtual int GoNext() = 0;

	virtual TKey GetKey()const = 0;
	virtual TValue GetValue()const = 0;

	friend ostream& operator<<(ostream &os, TTable &tab) {
		os << "Table printing" << endl;
		for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext()) {
			os << "Key: " << tab.GetKey() << " Val: " << tab.GetValue() << endl;
		}
		return os;
	}
};