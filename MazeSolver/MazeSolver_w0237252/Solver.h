#include <string>
#include<vector>
#include "stack.h"
#include "Cords.h"

using namespace std;

class Solver {

private:
		string fileout;
		stringstream ss;
		string fullString;
		int X = 0;
		int Y = 0;
		bool solved = false;
		int endX;
		int endY;
		Stack stackofCords;
		Cords currentCord;
public:
	Solver();
	string filenam;
	void solveMaze();
	void loadFile(string filename);
	void saveFile();
	bool checkClear(int x, int y);
	vector <vector<char>> Maze;
	vector <char> tempVector;

};