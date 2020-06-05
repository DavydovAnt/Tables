#pragma once
#include"THashTable.h"

#define TabHashStep 7

class TArrayHashTable : public THashTable {
protected:
	TTabRecord * pRecs;	//память для записи
	int TabSize;		//размер таблицы
	int HashStep;		//шаг вторичного перемешивания
	int FreePos;		//первая своб. строка, обнар. при поиске
	int CurrPos;		//номер текущей строки при завершении поиска
	TTabRecord Mark;	//маркер для строк с удал. записями
	TTabRecord Empty;	//маркер для незанятых строк

	//открытое перемешивание
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }

public:
	TArrayHashTable(int size = TabMaxSize, int Step = TabHashStep);
	virtual ~TArrayHashTable();

	//информационные методы
	virtual bool IsFull() const { return DataCount >= TabSize; }

	virtual bool FindRecord(TKey k);			//найти запись
	virtual int InsRecord(TKey k, TValue val);	//добавить запись
	virtual int DelRecord(TKey k);				//удалить запись

	//навигация
	virtual int Reset();				//установить на первую запись
	virtual int IsTabEnded() const;		//проверка на завершение таблицы
	virtual int GoNext();				//перейти к след записи

	//Доступ
	virtual TKey GetKey()const;
	virtual TValue GetValue()const;
};