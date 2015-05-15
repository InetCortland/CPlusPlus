#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "BST.h"
#include "Node.h"
using namespace std;
/* Source: http://en.wikipedia.org/wiki/AVL_tree  & http://stackoverflow.com/questions/10439681/balancing-a-binary-search-tree-bst */



#pragma region Balance


//Balanced Insert
	bool BST::Insert(Node*& sRoot, const std::string &data, bool &higher)
	{
		bool result = true;

		if (!sRoot){ //if null set up new root
			sRoot = new Node (data);
			higher = true;
		}
		else if (data == sRoot->getData()){ // Check if the new data is the same as the previous nodes data
			result = false;
			higher = false;
		}
		else if (data < sRoot->getData()){  // if new data is less then subroot data insert left
			result = Insert(sRoot->getLeft(), data, higher); // Recursively call the insert to the left
			if (higher) // if this node is higher then go into switch
				switch (sRoot->getBalance()){   // get the balance, go into cases
				case -1:
					leftside_Balance(sRoot);   // if the balance is -1 call left balance function
					higher = false;
					break;
				case 0:
					sRoot->setBalance(-1); // if this nodes balance is 0 set it to -1
					break;
				case 1:
					sRoot->setBalance(0); // if this nodes balance is 1 set it to 0
					higher = false;
					break;
			}
		}
		else{  // // if the data is greated then previous go right
			result = Insert(sRoot->getRight(), data, higher); // Recursively call the insert and put value into result
			if (higher) // the passed in higher value is checked
				switch (sRoot->getBalance()){    // this roots balance is checked
				case -1:
					sRoot->setBalance(0);    // if balance is -1 set to 0
					higher = false;
					break;
				case 0:
					sRoot->setBalance(1);   // if balance is 0 set to 1
					break;
				case 1:
					rightside_Balance(sRoot);  // if balance is 1 call right balance
					higher = false;
					break;
			}
		}
		return result;
	}

	// Balance and Rotate Helper Functions


	void BST::rightside_Balance(Node *&sRoot)
	{
		Node *&right_tree = sRoot->getRight();
		switch (right_tree->getBalance()){ // we check the balance value of right tree

		case 1: // if balance is 1 then set it to zero and rotate leftward for this node
			sRoot->setBalance(0);
			right_tree->setBalance(0);
			rotate_Leftward(sRoot); break;

		case 0:
			cout << "Error" << endl; break;

		case -1: // if -1 then create a temp node

					Node *subTree = right_tree->getLeft();
					switch (subTree->getBalance()){ // temp tree balance
					case 0:

						sRoot->setBalance(0); // set this nodes balance to 0
						right_tree->setBalance(0); break; //set the temp tree balance to 0
					case -1:

						sRoot->setBalance(0); // set this nodes balance 0
						right_tree->setBalance(1); break; // set temp balance 1

					case 1:
						sRoot->setBalance(-1); // set this nodes balance -1
						right_tree->setBalance(0); break; // set temp balance 0
			}
			subTree->setBalance(0);  //set temp node balance to 0
			rotate_Rightward(right_tree);   //rotate rightward using the temp righttree
			rotate_Leftward(sRoot); break;  // rotate this node leftward
		}
	}
	void BST::rotate_Leftward(Node *&sRoot)
	{
		if (sRoot == NULL || sRoot->getRight() == NULL)
			cout << "Error" << endl;
		else{
			Node *right_tree = sRoot->getRight(); // create temp node that is right of current node
			sRoot->setRight(right_tree->getLeft()); // set this nodes right to the temp nodes left
			right_tree->setLeft(sRoot);  // set temp trees left to this node
			sRoot = right_tree; // this node is = to right treee
		}
	}










	// NEVER GETS USED IN THIS ASSIGNMENT
	void BST::leftside_Balance(Node *&sRoot)
	{
		Node *&left_tree = sRoot->getLeft(); // temp node set to this nodes left
		switch (left_tree->getBalance()){ // switch using temp node 
		case -1:
			sRoot->setBalance(0);
			left_tree->setBalance(0);
			rotate_Rightward(sRoot); break;
		case 0:
			cout << "Error" << endl; break;
		case 1:
			Node *subTree = left_tree->getRight();
			switch (subTree->getBalance()){
			case 0:
				sRoot->setBalance(0);
				left_tree->setBalance(0); break;
			case -1:
				sRoot->setBalance(0);
				left_tree->setBalance(1); break;
			case 1:
				sRoot->setBalance(-1);
				left_tree->setBalance(0); break;
			}
			subTree->setBalance(0);
			rotate_Leftward(left_tree);
			rotate_Rightward(sRoot); break;
		}
	}
	void BST::rotate_Rightward(Node *&sRoot)
	{
		if (sRoot == NULL || sRoot->getLeft() == NULL)
			cout << "Error" << endl;
		else{
			Node *left_tree = sRoot->getLeft(); // temp node is created with same value as this nodes left value
			sRoot->setLeft(left_tree->getRight()); // set this roots left to the temp nodes right
			left_tree->setRight(sRoot);  // set temp node's right to the current node
			sRoot = left_tree; // set this node to the temp node
		}
	}

#pragma endregion Source: http://en.wikipedia.org/wiki/AVL_tree  & http://stackoverflow.com/questions/10439681/balancing-a-binary-search-tree-bst

/* Source: Hal O'Connell */
#pragma region TreeFunctions
	void BST::Insert(std::string num)
	{
		bool a = true;
		Insert(root, num, a);

	}

	void BST::PrintTree(std::ostream& output, NodePtr &node, int indent)
	{
		if (node != NULL)
		{
			
			PrintTree(output, node->right, indent + 8);

			output << setw(indent) << node->data << endl;

			PrintTree(output, node->left, indent + 8);
		}
	}
	std::ostream&  operator <<(ostream &output, BST &bst)
	{
		bst.PrintTree(output, bst.root, 5);

		return output;
	}
	bool BST::Search(std::string num)
	{
		bool found = false;
		NodePtr node = root;
		NodePtr parent = NULL;

		while (!found && (node != NULL))
		{
			if (num < node->data)
			{
				parent = node;
				node = node->left;
			}
			else if (num > node->data)
			{
				parent = node;
				node = node->right;
			}
			else
			{
				return true;
			}
		}

		return false;

	}

	/*
	void BST::Insert(std::string num, NodePtr &node)
	{
	if (node == NULL)
	{
	node = new Node();
	node->data = num;
	}
	else if (num < node->data)
	{
	Insert(num, node->left);
	}
	else if (num > node->data)
	{
	Insert(num, node->right);
	}
	else
	{
	cout << "Node value " << node->data << " already exists.";
	cout << endl;
	}
	}
	*/
	

	
#pragma endregion Source:  Hal O Connell


















