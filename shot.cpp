
#include "shot.h"

Shot::Shot(int x, int y) :
	Position::Coordinates(x, y)
{
}
Shot::Shot(char x, int y) :
	Position::Coordinates(0, 0) // assigned in following constructor
{
	if (x >= 65 && x <= 90) // is uppercase
		X = x - 65;
	else if (x >= 97 && x <= 122) // is lowercase
		X = x - 97;
	else
		X = -1;

	Y = y - 1;
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