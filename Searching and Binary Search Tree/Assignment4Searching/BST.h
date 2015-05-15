
#ifndef _BST_H
#define _BST_H


#include <istream>
#include <ostream>
#include "Node.h"
#include <string>



class BST
{

/* Source: http://en.wikipedia.org/wiki/AVL_tree  & http://stackoverflow.com/questions/10439681/balancing-a-binary-search-tree-bst /// Hal O'Connell */
public:
	typedef Node* NodePtr;
	NodePtr root;
	BST() : root(NULL) {}

	bool Insert(Node*& subRoot, const std::string &newData, bool &taller);
	void Insert(std::string num);
	void Insert(std::string num, NodePtr &node);
	bool Search(std::string num);
	void PrintTree(std::ostream& output, NodePtr &node, int indent);

	void rightside_Balance(Node *&subRoot);
	void leftside_Balance(Node *&subRoot);
	void rotate_Leftward(Node *&subRoot);
	void rotate_Rightward(Node *&subRoot);


	friend std::ostream& operator << (std::ostream &output, BST &bst);



};

#endif