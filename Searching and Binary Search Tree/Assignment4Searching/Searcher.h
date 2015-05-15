#include <string>
#include "BST.h"

#ifndef _Searcher_H
#define _Searcher_H

using namespace std;

class Searcher {

private:
	
	static const int maxSize = 50000;
	int unsortedarray[maxSize];
	int duplicatedarray[maxSize];
	double duration;
	

public:
	BST mybst;
	Searcher();
	void correctFile();
	void binarySearch();
	void loadFile();
	void sequentialSearch();
	void doSearch();
	void GenerateArray();
	void duplicateArray();
	void shuffle(int *arr, size_t n);
	int numberofnodes;

};
#endif