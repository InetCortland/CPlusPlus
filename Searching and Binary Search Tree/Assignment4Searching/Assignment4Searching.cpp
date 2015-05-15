// Assignment4Searching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Searcher.h"
#include <iostream>
#include <cctype>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{




	Searcher mysearcher;
	mysearcher.sequentialSearch();
	mysearcher.binarySearch();
		

	system("pause");


	return 0;
}

