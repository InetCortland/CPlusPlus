#include "stdafx.h"
#include <iostream>
#include "stacknode.h"


using namespace std;

StackNode::StackNode() : _data(), _next(NULL)
{
}

StackNode::StackNode(Cords data, StackNode* next) : _data(data), _next(next)
{
}

StackNode::~StackNode()
{
}

// returns the cord data
Cords StackNode::getData()
{
	return _data;
}
// sets the cord data
void StackNode::setData(Cords data)
{
	_data = data;
}
// gets the next cords data
StackNode* StackNode::getNext()
{
	return _next;
}
// sets the next cords data
void StackNode::setNext(StackNode *next)
{
	_next = next;
}
