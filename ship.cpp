/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  3
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the implementation of the Ship
  				  class.
********************************************************************/

#include "ship.h"
#include "position.h"

Ship::Ship(Position::Coordinates coordinates, Position::Orientation orientation, unsigned int length) :
	_coordinates(coordinates), _orientation(orientation), _length(length)
{
	if (length == 0)
		throw "Ship length must be greater than 0";
}
Position::Coordinates Ship::GetCoordinates() const
{
	return _coordinates;
}
void Ship::setCoordinates(Position::Coordinates coordinates)
{
	_coordinates = coordinates;
}
Position::Orientation Ship::getOrientation() const
{
	return _orientation;
}
void Ship::setOrientation(Position::Orientation orientation)
{
	_orientation = orientation;
}
unsigned int Ship::getLength() const
{
	return _length;
}
bool Ship::isSunk() const
{
	return _hits == _length; // assumes _length != 0
}
bool Ship::isHit(const Position::Coordinates& coordinates)
{
	Position::Coordinates shipCoordinates = _coordinates;

	for (int i = 0; i < _length; i++)
	{
		if (shipCoordinates == coordinates)
		{
			_hits++;
			return true;
		}
		else if (_orientation == Position::HORIZONTAL)
			shipCoordinates.X++;
		else
			shipCoordinates.Y++;
	}

	return false;
}