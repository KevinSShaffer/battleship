
#include "shot.h"

Shot::Shot(int x, int y) :
	Position::Coordinates(x, y)
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