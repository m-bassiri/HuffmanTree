#include "LeafNode.h"

LeafNode::LeafNode(char e, int w)
{
	this->element = e;
	this->weight = w;
}


char LeafNode::getElement()
{
	return this->element;
}

int LeafNode::getWeight()
{
	return this->weight;
}

bool LeafNode::isLeaf()
{
	return true;
}
