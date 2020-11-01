#pragma once
class BaseNode
{
public:
	virtual bool isLeaf() = 0;
	virtual int getWeight() = 0;
};

