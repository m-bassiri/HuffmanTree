#pragma once
#include "BaseNode.h"
class InternalNode :
	public BaseNode
{
private:
	int weight;
	BaseNode* leftChild;
	BaseNode* rightChild;
public:
	InternalNode(BaseNode* lc, BaseNode* rc, int w);
	BaseNode* getLeftChild();
	BaseNode* getRightChild();
	int getWeight();
	bool isLeaf();
};

