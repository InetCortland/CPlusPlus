#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Searcher.h"
#include "BST.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <regex>
#include <locale>


using namespace std;

Searcher::Searcher()
{
	
	GenerateArray();
	duplicateArray();
	doSearch();
}


// Source: Hal O'Connell
void Searcher::sequentialSearch()
{
	clock_t start;
	start = clock();

	// Loop towards the max size.
	// We do this to emulate searching for values 1-1000
	for (int target = 0; target < maxSize; target++)
		{

				bool found = false;
				int pos = -1;
				for (int i = 0; i < maxSize && found != true; i++)
					if (target+1 == duplicatedarray[i]){ pos = i; found = true; }
				//cout << "Position: " << pos << " Value: " << duplicatedarray[pos] << endl;
		}

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "--------------------- Search Times -------------------------------------" << endl;
	cout << "Total Searches: " << maxSize << endl;
	cout << "Sequential Search: " << duration << '\n';
}


/* BinarySearch Source: http://www.cs.utsa.edu/~wagner/CS3343/recursion/binsearch.html */
void Searcher::binarySearch() {
	clock_t start;
	start = clock();


	for (int target = 0; target < maxSize; target++)
	{
			int low = 0;
			int high = maxSize - 1;
			while (low <= high) 
			{
				int mid = (low + high) / 2;

				if (duplicatedarray[mid] == target)
					{ 
					//cout << mid << endl;
					break;
					}
				else if (duplicatedarray[mid] < target) 
					{
						low = mid + 1;
					}
				else
					{ 
						high = mid - 1; 
					}

			}
	}


	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Binary  Search: " << duration << '\n';
}
void Searcher::doSearch()
{


	loadFile();
	cout << mybst;
	cout << "---------------------Spell Check-------------------------------------"<< endl;
	correctFile();


}
void Searcher::GenerateArray()
{
	int i;

	for (i = 0; i<maxSize; i++){
		unsortedarray[i] = i+1;
	}

}
void Searcher::duplicateArray()
{
	// copy the array for use
	int i = 0;
	while (i < maxSize)
	{
		duplicatedarray[i] = unsortedarray[i];
		i++;
	}
}
// Load the Dictionary
void Searcher::loadFile()
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

	while (std::getline(file, str))

	{
		
		mybst.Insert(str);
		
	}
}
void Searcher::correctFile()
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

		for (int x=0; x < linestring.length(); x++)
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
				else if (ep == -1 && !isalpha(linestring[x+1]))
				{
					ep = x;
				}
			}

			if (sp != -1 && ep != -1)
			{
				//(sp, sp-ep+1)
				std::string str2 = linestring.substr(sp, ep-sp+1);
				
				std::string lowerstring;

				for (int j = 0; j < str2.length(); j++)
				{
					lowerstring += tolower(str2[j]);
				
				}


				
				bool found = mybst.Search(lowerstring);





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
