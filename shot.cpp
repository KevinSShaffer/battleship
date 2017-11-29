
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
	std::ostringstream sstream;
	sstream << (char)(X + 65);
	sstream << (Y + 1);

	return sstream.str();
}