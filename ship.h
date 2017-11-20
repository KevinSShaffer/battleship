/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  3
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the definitions for the Ship base
  				  class.
********************************************************************/
#ifndef SHIP_H
#define SHIP_H
#include "position.h"

class Ship
{
public:
	Ship(Position::Coordinates coordinates, Position::Orientation orientation, unsigned int length);
	Position::Coordinates GetCoordinates() const;
	void setCoordinates(Position::Coordinates coordinates);
	Position::Orientation getOrientation() const;
	void setOrientation(Position::Orientation orientation);
	unsigned int getLength() const;
	bool isSunk() const;
	bool isHit(const Position::Coordinates& coordinates);
private:
	Position::Coordinates _coordinates;
	Position::Orientation _orientation;
	unsigned int _length;
	unsigned int _hits;
};
#endif