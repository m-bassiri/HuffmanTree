#pragma once
#include "BaseNode.h"
class MinHeap
{
private:
	BaseNode **harr;
	int cap;
	int size;
public:
	MinHeap(int cap);
	void swap(BaseNode **x, BaseNode **y);
	void MinHeapify(int i);
	BaseNode* extractMin();
	void insertKey(BaseNode* k);
	bool lastElement();
	void rec_dest(BaseNode* target);
	~MinHeap();
};

