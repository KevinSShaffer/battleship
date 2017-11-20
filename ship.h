/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the definitions for the Ship base
  				  class.
********************************************************************/
#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <vector>
#include "position.h"

struct ShipToken
{
	std::string name;
	unsigned int length;
	char identifier;
};
class Ship
{
public:
	Ship(ShipToken, Position::Coordinates, Position::Orientation);
	Position::Coordinates GetCoordinates() const;
	void setCoordinates(Position::Coordinates);
	Position::Orientation getOrientation() const;
	void setOrientation(Position::Orientation);
	std::string getName() const;
	unsigned int getLength() const;
	bool isSunk() const;
	bool isHit(const Position::Coordinates&);
	std::vector<Position::Coordinates> getArea() const;
	char getIdentifier() const;
private:
	ShipToken _token;
	Position::Coordinates _coordinates;
	Position::Orientation _orientation;
	unsigned int _hits;
};
#endif