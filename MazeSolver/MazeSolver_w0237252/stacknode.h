#include "Cords.h"

#ifndef _STACKNODE_H
#define _STACKNODE_H

class StackNode
{
private:
	Cords _data;
	StackNode *_next;

public:
	StackNode();
	StackNode(Cords data, StackNode* next);
	virtual ~StackNode();

	Cords getData();
	void setData(Cords data);

	StackNode* getNext();
	void setNext(StackNode *next);
};

#endif
