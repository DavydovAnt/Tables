#include "TArrayTable.h"



TKey TArrayTable::GetKey(TDataPos mode) const {
	if ((DataCount == 0) || (CurrPos >= DataCount))
		throw -1;
	return pRecs[CurrPos].Key;
}	

TValue TArrayTable::GetValue(TDataPos mode) const {
	if ((DataCount == 0) || (CurrPos >= DataCount))
		throw -1;
	return pRecs[CurrPos].Value;
}

int TArrayTable::Reset() {
	CurrPos = 0;
	return IsTabEnded();
}

int TArrayTable::IsTabEnded() const {
	return CurrPos >= DataCount;
}

int TArrayTable::GoNext() {
	if (!IsTabEnded()) CurrPos++;
	return IsTabEnded();
}

int TArrayTable::SetCurrentPos(int pos) {
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsTabEnded();
}