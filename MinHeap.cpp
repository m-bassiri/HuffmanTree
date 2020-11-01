#include "MinHeap.h"
#include "InternalNode.h"

MinHeap::MinHeap(int cap)
{
	this->size = 0;
	this->cap = cap;
	harr = new BaseNode*[cap];
}

void MinHeap::swap(BaseNode ** x, BaseNode ** y)
{
	BaseNode *temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::MinHeapify(int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int smallest = i;
	if (l < size && harr[l]->getWeight() < harr[i]->getWeight())
		smallest = l;
	if (r < size && harr[r]->getWeight() < harr[smallest]->getWeight())
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

BaseNode * MinHeap::extractMin()
{
	if (size == 1)
	{
		size--;
		return harr[0];
	}

	BaseNode* root = harr[0];
	harr[0] = harr[size - 1];
	size--;
	MinHeapify(0);

	return root;
}

void MinHeap::insertKey(BaseNode * k)
{
	if (size == cap)
	{
		return;
	}

	size++;
	int i = size - 1;
	harr[i] = k;

	while (i != 0 && harr[(i - 1) / 2]->getWeight() > harr[i]->getWeight())
	{
		swap(&harr[i], &harr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

bool MinHeap::lastElement()
{
	return this->size == 1;
}

void MinHeap::rec_dest(BaseNode * target)
{
	if (target->isLeaf()) {
		delete target;
		target = nullptr;
		return;
	}
	InternalNode* t = dynamic_cast<InternalNode*>(target);
	rec_dest(t->getLeftChild());
	rec_dest(t->getRightChild());
	delete target;
	target = nullptr;
	return;
}

MinHeap::~MinHeap()
{
	rec_dest(harr[0]);
	delete harr;
	harr = nullptr;
}
