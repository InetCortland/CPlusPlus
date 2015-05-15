
#include <string>
#include<vector>

#ifndef _CORDS_H
#define _CORDS_H

using namespace std;

class Cords {

private:

public:
	Cords();
	Cords(int x, int y);
	int valy;
	int valx;
	void setY(int y);
	void setX(int x);
	int getY();
	int getX();
};
#endif