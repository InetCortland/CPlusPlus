#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Hash.h"

using namespace std;


hasher::hasher()
	{
	for (i = 0; i < tableSize; i++)
	{
		HashTable[i] = new Node;
		HashTable[i]->word = "";
		HashTable[i]->next = NULL;

	}
	
	}
int hasher::Hash(std::string key)
	{

	sum = 0;
	int len = key.length();
	for (i = 0; i < len; i++)
		sum += (int)key[i]; // cast each character of the string as int to get ascii value

	// the modulus, or remainder, of integer division gives a result between 0 and the size-1
	address = sum % tableSize;



	return address;
}
void hasher::AddNode(string word)
{

	int index = Hash(word); // get address of the first word

	if (HashTable[index]->word == "") // if its empty index
	{
		HashTable[index]->word = word; // make index value = input word
	}
	else // if index isnt empty go down chain
	{
		Node* Ptr = HashTable[index];

		Node* n = new Node; // create new temp Node and fill with current data
		n->word = word;

		n->next = NULL;

		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next; // go down chain to reach the end
		
		}
		Ptr->next = n;
	
	}


}
int hasher::getNumberofNodes(int index)
{
	int count = 0;
	// check to see if value is null
	if (HashTable[index]->word == "")
		{
			return count;
		}
	else 
		{ // go deeper in chain
			count++;
			Node* Ptr = HashTable[index];
				while (Ptr->next != NULL)
					{
						count++;	
						Ptr = Ptr->next;
					}


		
		}



	return count;

}
void hasher::PrintNodesinIndex(int index)
	{
			// this prints all the Nodes in an index
		Node* Ptr = HashTable[index]->next;

			// if the current chain index is null do nothing
		if (Ptr->word == "")
		{
		
		
		}
		else   // else indent and print values in a loop until the pointer to the next is !null
		{
		
			while (Ptr != NULL)
			{
				int indent = 25;
				cout << setw(indent) << "____________\n";
				cout << setw(indent - 8) << " Word: " << Ptr->word << endl;
				cout << setw(indent) << "____________\n";

					Ptr = Ptr->next;
			
			}
		
		
		}




	}
void hasher::PrintTable()
	{
		
		int number;
		for (int i = 0; i < tableSize; i++) //go to total table size
		{
			number = getNumberofNodes(i); // find number of Nodes in the current index

			cout << "----------------------------------------\n";
			cout << endl;
			cout << "Index = " << i << endl;
			
			if (number > 1){ // if number of Nodes in index is > 1 print all list
				cout << "____________\n";
				cout << " Word: " << HashTable[i]->word << endl;
				cout << "____________\n";
				PrintNodesinIndex(i);

			}
			else { // if number of Nodes in index is only 1, print 1 value
				cout << "____________\n";

				cout << " Word: " << HashTable[i]->word << endl;
				cout << "____________\n";
			}
			cout << endl;
			cout << "----------------------------------------\n";
		}


	}
void hasher::loadFile()
{

	string filename = "dictionary.txt";
	ifstream file;
	string lineOne;
	string str;

	file.open(filename);

	if (file.fail())
	{
		std::cerr << "Error Opening File" << std::endl;
		return;
	}
	// while we can read add Nodes using the addNode method
	while (std::getline(file, str))

	{
		AddNode(str);
	}
}
void hasher::loadmispelled()
{
	string filename = "mispelled.txt";
	ifstream file;
	string lineOne;
	string linestring;

	file.open(filename);

	if (file.fail())
	{
		std::cerr << "Error Opening File" << std::endl;
		return;
	}

	while (std::getline(file, linestring))
	{

		int sp = -1, ep = -1;

		for (int x = 0; x < linestring.length(); x++)
		{
			if (isalpha(linestring[x]))
			{
				if (sp == -1)
				{
					sp = x;
					if (!isalpha(linestring[x + 1]))
					{
						ep = x;
					}
				}
				else if (ep == -1 && !isalpha(linestring[x + 1]))
				{
					ep = x;
				}
			}

			if (sp != -1 && ep != -1)
			{
				//(sp, sp-ep+1)
				std::string str2 = linestring.substr(sp, ep - sp + 1);

				std::string lowerstring;

				for (int j = 0; j < str2.length(); j++)
				{
					lowerstring += tolower(str2[j]);

				}

				bool found = Search(lowerstring);

				if (!found)
				{
					cout << lowerstring << " was not found." << endl;
				}
				lowerstring = "";
				str2 = "";
				sp = -1;
				ep = -1;

			}



		}

	}



}
bool hasher::Search(string findstring)
{
	int wordcount = 0;

	int searchindex = Hash(findstring);

	for (int i = searchindex; i < tableSize; i++) //go to total table size
	{
		
		Node* Ptr = HashTable[i]; // look at hastable index

		if (Ptr->word == findstring)
		{
			return true;
		}
		else  
		{ // it has a word

			while (Ptr->next != NULL)//check if there is more on chain
				{
					Ptr = Ptr->next;
					if (findstring == Ptr->word){
						return true;
					}
				}
		}// end else for start of chain
	}// end for loop hash table size


	return false;
}

