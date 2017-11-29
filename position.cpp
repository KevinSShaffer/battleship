/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  3
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the member functions for the coordinates
  				  class.
********************************************************************/

#include "position.h"

Position::Coordinates::Coordinates(int x, int y) :
	X(x), Y(y)
{ }
Position::Coordinates::Coordinates(std::string coordinates)
{
	if (coordinates.size() < 2)
	{
		X = -1;
		Y = -1;
	}
	else
	{
		char x = coordinates[0];
		int y = std::stoi(coordinates.substr(1, coordinates.size() - 1));

		if (x >= 65 && x <= 90) // is uppercase
			X = x - 65;
		else if (x >= 97 && x <= 122) // is lowercase
			X = x - 97;
		else
			X = -1;

		Y = y - 1;
	}
}
bool Position::Coordinates::operator==(const Position::Coordinates other)
{
	return X == other.X && Y == other.Y;
}