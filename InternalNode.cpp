#include "InternalNode.h"

InternalNode::InternalNode(BaseNode * lc, BaseNode * rc, int w)
{
	this->leftChild = lc;
	this->rightChild = rc;
	this->weight = w;
}

BaseNode * InternalNode::getLeftChild()
{
	return this->leftChild;
}

BaseNode * InternalNode::getRightChild()
{
	return this->rightChild;
}

int InternalNode::getWeight()
{
	return this->weight;
}

bool InternalNode::isLeaf()
{
	return false;
}
