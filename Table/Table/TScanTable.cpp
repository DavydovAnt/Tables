#include "TScanTable.h"



bool TScanTable::FindRecord(TKey k) {

	int i=0;
	for (i = 0; i < DataCount; i++) {
		Efficiency++;
		if (pRecs[i].Key == k) break;
	}
	if (i < DataCount) {
		CurrPos = i;
		return true;
	}
	return false;
}
int TScanTable::InsRecord(TKey k, TValue val) {
	if (IsFull()) {
		return TabFull;
	}
	else {
		bool res = FindRecord(k);
		if (res == true) {
			return TabRecDbl;
		}
		else {
			pRecs[DataCount] = TTabRecord(k, val);
			DataCount++;
			return TabOK;
		}
	}
}
int TScanTable::DelRecord(TKey k) {
	if (IsEmpty()) {
		return TabEmpty;
	}
	else {
		bool res = FindRecord(k);
		if (res == false) {
			return TabNoRec;
		}
		else {
			pRecs[CurrPos] = pRecs[DataCount-1];
			Efficiency++;
			DataCount--;
			return TabOK;
		}
	}
}