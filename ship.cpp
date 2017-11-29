/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the implementation of the Ship
  				  class.
********************************************************************/

#include "ship.h"

Ship::Ship() :
	_coordinates(-1, -1)
{
}
Ship::Ship(std::string csvLine) :
	_coordinates(-1, -1), _hits(0)
{
	words values = str_func::split(csvLine, ',');

	if (values.size() != 3 ||
		!tryParse(values[0], _token) ||
		!tryParse(values[2], _orientation))
		throw UnableToInitialize(csvLine);
	else
		_coordinates = Position::Coordinates(values[1]);
}
Ship::Ship(ShipToken shipToken, Position::Coordinates coordinates, Position::Orientation orientation) :
	_token(shipToken), _coordinates(coordinates), _orientation(orientation), _hits(0)
{
	if (_token.length == 0)
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
std::string Ship::getName() const
{
	return _token.name;
}
unsigned int Ship::getLength() const
{
	return _token.length;
}
bool Ship::isSunk() const
{
	return _hits == _token.length; // assumes _length != 0					// this should check locations of hits
}
bool Ship::isHit(const Position::Coordinates& coordinates)
{
	std::vector<Position::Coordinates> area = getArea();

	for (unsigned int i = 0; i < _token.length; i++)
	{
		if (area[i] == coordinates)
		{
			_hits++;														// this should keep track of where it was hit
			return true;
		}
	}

	return false;
}
std::vector<Position::Coordinates> Ship::getArea() const
{
	std::vector<Position::Coordinates> area;

	for (unsigned int i = 0; i < _token.length; i++)
	{
		if (_orientation == Position::HORIZONTAL)
			area.push_back(Position::Coordinates(_coordinates.X + i, _coordinates.Y));
		else
			area.push_back(Position::Coordinates(_coordinates.X, _coordinates.Y + i));
	}

	return area;
}
bool Ship::isCollision(Ship otherShip) const
{
	using area = std::vector<Position::Coordinates>;
	area thisArea = getArea();
	area otherArea = otherShip.getArea();

	for (int i = 0; i < thisArea.size(); i++)
	{
		for (int j = 0; j < otherArea.size(); j++)
		{
			if (thisArea[i] == otherArea[j])
				return true;
		}
	}

	return false;
}
char Ship::getIdentifier() const
{
	return _token.identifier;
}
bool Ship::tryParse(std::string word, ShipToken& token)
{
	word = str_func::toLower(word);

	if (word == "carrier")
	{
		token = { "Carrier", 5, 'r' };
	}
	else if (word == "battleship")
	{
		token = { "Battleship", 4, 'b' };
	}
	else if (word == "cruiser")
	{
		token = { "Cruiser", 3, 'c' };
	}
	else if (word == "submarine")
	{
		token = { "Submarine", 3, 'u' };
	}
	else if (word == "destroyer")
	{
		token = { "Destroyer", 2, 'd' };
	}
	else
		return false;

	return true;
}
bool Ship::tryParse(std::string word, Position::Orientation& orientation)
{
	if (word.size() > 0)
	{
		switch (str_func::toLower(word)[0])
		{
		case 'h':
			orientation = Position::Orientation::HORIZONTAL;
			return true;
		case 'v':
			orientation = Position::Orientation::VERTICAL;
			return true;
		default:
			return false;
		}
	}
	else
		return false;
}