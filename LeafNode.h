#pragma once
#include "BaseNode.h"
class LeafNode :
	public BaseNode
{
private:
	char element;
	int weight;
public:
	char getElement();
	int getWeight();
	bool isLeaf();
	LeafNode(char e, int w);
};

