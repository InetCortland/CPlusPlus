#include <iostream> 
#include <string>
#include "Hash.h"
#include <iostream>     
#include <iomanip>      
using namespace std;

#define SIZE 11  // Size of the sample hash table - note the use of a prime number
#define DEBUG TRUE;





int main(int argc, char* argv[])
{
	clock_t start;

	hasher hashObj;
	double duration;

	hashObj.loadFile();
    hashObj.PrintTable();



	start = clock();
	hashObj.loadmispelled();


	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << '\n' << "Time to SpellCheck: " << duration << '\n';

	cin.ignore();
	return 0;
}

