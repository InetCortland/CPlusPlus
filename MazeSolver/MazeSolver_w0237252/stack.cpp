#include "stdafx.h"
#include <iostream>
#include "stacknode.h"
#include "stack.h"
#include <ostream>

using namespace std;


Stack::Stack() : _top(NULL)
{
}

Stack::~Stack()
{
	while (_top != NULL)
	{
		Pop();
	}
}

// pushes input cord to the top of the stack
myerror_code Stack::Push(Cords num)
{
	_top = new StackNode(num, _top);
	return(success);
}

// pulls out the top cord
Cords Stack::Peek()
{
	return _top->getData();
}

	// Removes top cord
myerror_code Stack::Pop()
{
	StackNode* node = _top;
	_top = _top->getNext();
	delete node;
	return(success);
}

// Never used, but allows for output.
ostream& operator<<(ostream& output, Stack& stack)
{
	StackNode *node = stack._top;

	while (node != NULL)
	{
		cout << node->getData().getX() << endl;
		cout << node->getData().getY() << endl;
		node = node->getNext();
	}

	return output;
}

