#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef int TKey;
typedef string TValue;

class TTabRecord {
protected:
	TKey Key;
	TValue Value;
public:
	TTabRecord(){}
	TTabRecord(TKey k) { Key = k; }
	TTabRecord(TKey k, TValue v) { Key = k; Value = v; }
	void SetKey(TKey k) { Key = k; }
	TKey GetKey() { return Key; }
	void SetValue(TValue v) { Value = v; }
	TValue GetValue() { return Value; }
	virtual int operator==(const TTabRecord &tr) { return Key == tr.Key; }
	virtual int operator!=(const TTabRecord &tr) { return Key != tr.Key; }
	virtual int operator>(const TTabRecord &tr) { return Key > tr.Key; }
	virtual int operator<(const TTabRecord &tr) { return Key < tr.Key; }
	friend ostream& operator<<(ostream &os, const TTabRecord &tr) {
		return os << tr.Key << " " << tr.Value;
	}
	friend class TSortTable;
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TArrayHashTable;
	friend class TTreeTable;
};