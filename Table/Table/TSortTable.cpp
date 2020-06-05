#include "TSortTable.h"

TSortTable::TSortTable(const TScanTable &tab) {
	*this = tab;
}

TSortTable & TSortTable::operator =(const TScanTable &tab) {

	if (pRecs != NULL) {
		delete[] pRecs;
		pRecs = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new TTabRecord[TabSize];
	for (int i = 0; i < DataCount; i++) {
		pRecs[i] = tab.pRecs[i];
	}
	SortData();
	CurrPos = 0;
	return *this;
}

bool TSortTable::FindRecord(TKey k) {
	int i, i1 = 0, i2 = DataCount - 1;
	while (i1 <= i2) {
		Efficiency++;
		i = (i1 + i2) / 2;
		if (pRecs[i].Key == k) {
			i1 = i + 1;
			i2 = i;
			break;
		}
		if (pRecs[i].Key > k) i2 = i - 1;
		else i1 = i + 1;
	}
	if ((i2 < 0) || (pRecs[i2].Key < k)) i2++;
	CurrPos = i2;
	if ((i2 < DataCount) && (pRecs[i].Key == k)) {
		return true;
	}
	return false;
}

int TSortTable::InsRecord(TKey k, TValue val) {
	if (IsFull()) {
		return TabFull;
	}
	else {
		bool res = FindRecord(k);
		if (res == true) {
			return TabRecDbl;
		}
		else {
			for (int i = DataCount; i > CurrPos; i--) {
				pRecs[i] = pRecs[i - 1];
				Efficiency++;
			}
			pRecs[CurrPos] = TTabRecord(k, val);
			DataCount++;
			return TabOK;
		}
	}
}

int TSortTable::DelRecord(TKey k) {
	if (IsEmpty()) {
		return TabEmpty;
	}
	else {
		bool res = FindRecord(k);
		if (res == false) {
			return TabNoRec;
		}
		else {
			for (int i = CurrPos; i < DataCount - 1; i++) {
				pRecs[i] = pRecs[i + 1];
				Efficiency++;
			}
			DataCount--;
			return TabOK;
		}
	}
}

void TSortTable::SortData() {
	switch (SortMethod)
	{
	case SELECT_SORT:
		SelectSort();
		break;
	case QUICK_SORT:
		QuickSort();
		break;
	}
}

void TSortTable::SelectSort() {
	int index = 0;
	for (int i = 0; i < DataCount; i++) {
		index = i;//номер текущего мин элемента
		for (int j = i + 1; j < DataCount; j++) {
			Efficiency++;
			if (pRecs[j] < pRecs[index]) {
				index = j;
			}
		}
		if (i != index) {
			Efficiency++;
			//обмен записей i и index
			TTabRecord tmp = pRecs[i];
			pRecs[i] = pRecs[index];
			pRecs[index] = tmp;
		}
	}
}

void TSortTable::QuickSort() {
	QuickSorter(0, DataCount - 1);
}

void TSortTable::QuickSorter(int first, int last) {
	int i, j; TTabRecord x;
	i = first; j = last;
	x = pRecs[(first + last) / 2];
	while (i < j) {
		Efficiency += 2;
		while (pRecs[i] < x) i++;
		while (pRecs[j] > x) j--;
		if (i <= j) {
			Efficiency++;
			TTabRecord tmp = pRecs[i];
			pRecs[i] = pRecs[j];
			pRecs[j] = tmp;
			i++; j--;
		}
	}
	if (first < j) QuickSorter(first, j);
	if (i < last) QuickSorter(i, last);
}
