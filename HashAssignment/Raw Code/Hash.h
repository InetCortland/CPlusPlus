#include <iostream> 
#include <string>

#ifndef _hash_H
#define _hash_H


using namespace std;

class hasher
{
	public:

		hasher();
		int Hash(string key);

		static const int tableSize=13;

		void AddNode(string word);
		int getNumberofNodes(int index);
		void PrintTable();
		void PrintNodesinIndex(int index);
		void loadFile();
		void loadmispelled();
		bool Search(string findstring);
	private:

		
		struct Node{
			string word;
			Node* next;

		};
		Node* HashTable[tableSize];
		int i, sum, address;
};

#endif 









