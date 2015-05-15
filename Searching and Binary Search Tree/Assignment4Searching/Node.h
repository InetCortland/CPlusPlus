#ifndef _Node_H
#define _Node_H


class Node
{


/*Source: http://en.wikipedia.org/wiki/AVL_tree  & http://stackoverflow.com/questions/10439681/balancing-a-binary-search-tree-bst */
#pragma region Node Functions & Variables

public:
	Node* right;
	Node* left;
	int balance;

	//set balance
	void setBalance(int b)
	{ balance = b; }


	//get balance
	int getBalance()
	{ return balance; }



	// set right node
	void setRight(Node* newNext)
	{ right = newNext; }
	//set left node
	void setLeft(Node* newPrevious)
	{ left = newPrevious; }
	// get right node const
	Node* getRight() const
	{ return right; }
	// get left node const
	Node* getLeft() const
	{ return left; }


	//get right node
	Node*& getRight()
	{ return right; }


	//get left node
	Node*& getLeft()
	{ return left; }

	//get const node value
	std::string getData() const
	{ return data; }
	// get node value
	std::string& getData()
	{ return data; }

	// Set node value
	void setData(int newData)
	{ data = newData; }
	std::string data;


	// Constructor
	Node(std::string newData){
		data = newData;
		left = NULL;
		balance = 0;
		right = NULL;
	}
#pragma endregion Source: http://en.wikipedia.org/wiki/AVL_tree  & http://stackoverflow.com/questions/10439681/balancing-a-binary-search-tree-bst





};


#endif