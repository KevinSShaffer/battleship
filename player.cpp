
#include "player.h"

Player::Player(std::string name)
{
	_name = name;
}
Player::getName() const
{
	return _name;
}
bool Player::isHit(const Coordinates shot)
{
	return true; // for testing
}