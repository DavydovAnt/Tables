#pragma once
#include"Record.h"

class TTreeNode : public TTabRecord {
protected:
	TTreeNode *pLeft, *pRight;
public:
	TTreeNode() { pLeft = pRight = NULL; }
	TTreeNode(TKey k, TValue val, TTreeNode *pL = NULL, TTreeNode *pR = NULL)
		:TTabRecord(k, val), pLeft(pL), pRight(pR) {}

	TTreeNode* GetLeft()const { return pLeft; }
	TTreeNode* GetRight()const { return pRight; }

	friend class TTreeTable;
};