#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Cords.h"
#include <iostream>


using namespace std;

// Cords object that holds two int values
Cords::Cords()
{

}
Cords::Cords(int x, int y)
{
	valy = y;
	valx = x;
}

// Cord var Setters
void Cords::setY(int in)
{
	valy = in;

}
void Cords::setX(int in)
{
	 valx=in;

}
// Cord var Getters
int Cords::getY()
		{
		return valy;

		}
int Cords::getX()
	{
		return valx;

	}