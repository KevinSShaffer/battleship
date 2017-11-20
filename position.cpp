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
bool Position::Coordinates::operator==(const Position::Coordinates other)
{
	return X == other.X && Y == other.Y;
}