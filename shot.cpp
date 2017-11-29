
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
std::string Shot::toString() const
{
	std::string str;
	str += (char)(X + 65);
	str += (char)(Y + 49);

	return str;
}