#include "TArrayHashTable.h"

TArrayHashTable::TArrayHashTable(int size, int Step):TabSize(size), HashStep(Step) {
	pRecs = new TTabRecord[TabSize];
	Empty = TTabRecord(-1);
	Mark = TTabRecord(-2);
	for (int i = 0; i < TabSize; i++) {
		pRecs[i] = Empty;
	}
}

TArrayHashTable::~TArrayHashTable() {
	delete[]pRecs;
}


//найти запись
bool TArrayHashTable::FindRecord(TKey k) {
	bool result = false;
	FreePos = -1;
	CurrPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++) {
		Efficiency++;
		if (pRecs[CurrPos] == Empty)			
			break;
		else if (pRecs[CurrPos] == Mark) {	
			if (FreePos == -1)
				FreePos = CurrPos;
		}
		else if (pRecs[CurrPos].Key == k) {		
			result = true;
			break;
		}
		CurrPos = GetNextPos(CurrPos);		
	}
	return result;
}

//добавить запись
int TArrayHashTable::InsRecord(TKey k, TValue val) {
	if (IsFull()) {
		return TabFull;
	}
	else {
		bool res = FindRecord(k);
		if (res == true) {
			return TabRecDbl;
		}
		else {
			if (FreePos = !- 1)
				CurrPos = FreePos;//используем 1ую пустую строку
			pRecs[CurrPos] = TTabRecord(k, val);
			DataCount++;
			return TabOK;
		}
	}
}

//удалить запись
int TArrayHashTable::DelRecord(TKey k) {
	if (IsEmpty()) {
		return TabEmpty;
	}
	else {
		bool res = FindRecord(k);
		if (res == false) {
			return TabNoRec;
		}
		else {
			pRecs[CurrPos] = Mark;
			DataCount--;
			return TabOK;
		}
	}
}


//Навигация
int TArrayHashTable::Reset() {
	CurrPos = 0;
	while (CurrPos < TabSize) {	//поиск 1ой занятной строки
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark)) {
			break;
		}
		else { CurrPos++; }
	}
	return IsTabEnded();
}

int TArrayHashTable::IsTabEnded() const {
	return CurrPos >= TabSize;
}

int TArrayHashTable::GoNext() {
	CurrPos++;
	while (CurrPos < TabSize) {	//поиск след. занятной строки
		if ((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark)) {
			break;
		}
		else { CurrPos++; }
	}
	return IsTabEnded();
}


//Доступ
TKey TArrayHashTable::GetKey()const {
	if ((DataCount == 0) || (CurrPos >= TabSize))
		throw -1;
	return pRecs[CurrPos].Key;
}

TValue TArrayHashTable::GetValue()const {
	if ((DataCount == 0) || (CurrPos >= TabSize))
		throw -1;
	return pRecs[CurrPos].Value;
}