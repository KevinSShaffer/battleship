/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  3
*  Due Date    :  Sep 26th, 2017
*  Description :  Contains the implementation of the WaterVechile
  				  class.
********************************************************************/

#include "water_vehicle.h"
#include "position.h"

WaterVehicle::WaterVehicle(Position::Coordinates coordinates, Position::Orientation orientation, unsigned int length) :
	_coordinates(coordinates), _orientation(orientation), _length(length)
{
	if (length == 0)
		throw "Ship length must be greater than 0";
}

Position::Coordinates WaterVehicle::GetCoordinates() const
{
	return _coordinates;
}
void WaterVehicle::SetCoordinates(Position::Coordinates coordinates)
{
	_coordinates = coordinates;
}
Position::Orientation WaterVehicle::GetOrientation() const
{
	return _orientation;
}
void WaterVehicle::SetOrientation(Position::Orientation orientation)
{
	_orientation = orientation;
}
unsigned int WaterVehicle::GetLength() const
{
	return _length;
}
bool WaterVehicle::IsSunk() const
{
	return _hits == _length; // assumes _length != 0
}
bool WaterVehicle::IsHit(const Position::Coordinates& coordinates)
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