// MazeSolver_w0237252.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "stdafx.h"
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Solver.h"

using namespace std;

void solveMazes();

int _tmain(int argc, _TCHAR* argv[])
{
	solveMazes();
	return 0;
}


	// This function just does all the maze solving.
void solveMazes()
	{
	// We create one solver for each maze.
	Solver solverOne;
	cout << "maze1.txt" << endl;
	solverOne.loadFile("maze1.txt");
	solverOne.solveMaze();
	system("pause");

	Solver solverTwo;
	cout << "maze2.txt" << endl;
	solverTwo.loadFile("maze2.txt");
	solverTwo.solveMaze();
	system("pause");

	Solver solverThree;
	cout << "maze3.txt" << endl;
	solverThree.loadFile("maze3.txt");
	solverThree.solveMaze();
	system("pause");

	Solver solverFour;
	cout << "maze4.txt" << endl;
	solverFour.loadFile("maze4.txt");
	solverFour.solveMaze();
	system("pause");

	cout << "mazex.txt" << endl;
	Solver solverX;
	solverX.loadFile("mazex.txt");
	solverX.solveMaze();
	system("pause");

	}





