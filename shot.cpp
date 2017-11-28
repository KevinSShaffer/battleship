
#include "shot.h"

Shot::Shot(Position::Coordinates coordinates) :
	_coordinates(coordinates)
{
}
bool Shot::isHit() const
{
	return _isHit;
}
void Shot::makeHit()
{
	_isHit = true;
}
void Shot::makeMiss()
{
	_isHit = false;
}