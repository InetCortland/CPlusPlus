#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Solver.h"
#include <iostream>
#include <vector>
#include "stack.h"
#include <chrono>
#include <thread>

using namespace std;
void solveMaze();
// Constructor
Solver::Solver()
	{
				
		stringstream ss;
		string fullString;
		int X = 0; // cords
		int Y = 0; // cords
		bool solved=false;
		// Vector 2d Array
		std::vector <std::vector<char>> Maze;
		// Temp Vector for when we load the maze in
		std::vector <char> tempVector;
		// end points for the maze size
		int endX;
		int endY;
		// Our stack of Cordinates
		Stack stackofCords;
		// Our currentCordinate
		Cords currentCord;
		filenam = "";
	}

// Solve maze Function.
void Solver::solveMaze()
	{

	// This finds the end point of the maze, and the start is always 1 , 0
	endX = Maze[0].size()-1;
	endY = Maze.size() -2;

	// 0,1 starting position for all mazes
	X = 0;
	Y = 1;
	// Set the current cord and push the cord on the stack before we start.
	currentCord.setX(X);
	currentCord.setY(Y);
	stackofCords.Push(currentCord);
	

	//While our maze isn't solved this loop will keep trying.
	while (!solved)
		{
			// check to see if the current cord is = to the end X and Y
		if (Y == endY && X == endX)
			{
			Maze[Y][X] = '@';
				solved = true;

				char k;
				int w = 0; // X
				int e = 0; // y
				while (w < Maze.size())
				{
					while (e < Maze[w].size())
					{
						k = Maze[w][e];
						cout << k;

						e++;
					}
					cout << endl;
					e = 0;
					w++;
				}


				break;
			}
		else
		{
			// If we fail to be at the end of the maze this code executes.
			// This will try go to north,south,east and west to find empty routes.


			// Look South -- Check to see its clear and inside of the maze as well as its not @ which is an been there ID
			if (checkClear(Y + 1, X))
			{
				Y++;
				Maze[currentCord.getY()][currentCord.getX()] = '@';
				currentCord.setX(X);
				currentCord.setY(Y);
				stackofCords.Push(currentCord);

			}
			//Look East-- Check to see its clear and inside of the maze as well as its not @ which is an been there ID

			else if (checkClear(Y, X + 1))
			{

				X++;
				Maze[currentCord.getY()][currentCord.getX()] = '@';	
				currentCord.setX(X);
				currentCord.setY(Y);
				stackofCords.Push(currentCord);
			}
			//Look north -- Check to see its clear and inside of the maze as well as its not @ which is an been there ID
			else if (checkClear(Y - 1, X))
			{

				Y--;
				Maze[currentCord.getY()][currentCord.getX()] = '@';
				currentCord.setX(X);
				currentCord.setY(Y);
				stackofCords.Push(currentCord);
			}


			//Look West -- Check to see its clear and inside of the maze as well as its not @ which is an been there ID
			else if (checkClear(Y, X - 1))
			{
				X--;
				Maze[currentCord.getY()][currentCord.getX()] = '@';
				currentCord.setX(X);
				currentCord.setY(Y);
				stackofCords.Push(currentCord);
			}
			else
			{
				// We were unable to find any empty space around us, time to backtrack....
				// We do this by removing stacks and checking more.
				// We also put X's down to let us know this place is a dead end.
				int chk = 0;
					
					Maze[stackofCords.Peek().getY()][stackofCords.Peek().getX()] = 'X';
					chk = stackofCords.Pop();
					currentCord.setX(stackofCords.Peek().getX());
					currentCord.setY(stackofCords.Peek().getY());
					X = currentCord.getX();
					Y = currentCord.getY();


					if (chk != 0){
						cout << "Stuck inside of maze?????";
						break;
					}
			


			}

		}// end else for solved check
	
		}// end Whileloop

		// Saves the solved maze to the file... Or the unsolved maze....
	saveFile();
	
}//end of solve Maze

// Loads a file into the maze solver object
void Solver::loadFile(string filename)
{
	filenam = filename;
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

		lineOne = str;

		for (char& c : lineOne) {

			Y++;

			tempVector.push_back(c);
			
		}
		Maze.push_back(tempVector);
		tempVector.clear();
		


		Y = 0;
		X++;
		lineOne = str;
	}

	X = 0;
	Y = 0;



	
	//cout << Maze.size();
	//cout << Maze[1].size();
	//cout << Maze.max_size;
	/*
	char k;
	while (X < Maze.size())
	{
		while (Y < Maze[X].size())
		{
			k = Maze[X][Y];
			cout << k;
			
			Y++;
		}
		Y = 0;
		X++;
	}*/



}
// checks if the node is clear by using given int values
bool Solver::checkClear(int Y, int X)
{
	if (Y < Maze.size() && X < Maze[0].size() && Y >= 0 && X >= 0){

		if (Maze[Y][X] == ' ' && Maze[Y][X] != '@' && Maze[Y][X] != 'X')
		{
			return true;

		}
		else return false;
	}
	else return false;
}
// Outputs the solved maze to a file
void Solver::saveFile()
{
	string filename = filenam;
	stringstream ss;
	string fullString;
	ofstream myfile;
	filename = "_" +  filename + "solved.txt";
	myfile.open(filename);

	char k;
	int w = 0; // X
	int e = 0; // y

	while (w < Maze.size())
	{
		while (e < Maze[w].size())
			{
				k = Maze[w][e];
				myfile << k;
				e++;
			}

		myfile << endl;
		e = 0;
		w++;
	}
	myfile.close();


}