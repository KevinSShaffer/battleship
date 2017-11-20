
#include "player.h"

Player::Player(std::string name) :
	_name(name)
{
}
std::string Player::getName() const
{
	return _name;
}
bool Player::isHit(const Position::Coordinates shot)
{
	return _theirBoard.isHit(shot);
}
bool Player::placeShip(const Ship ship)
{
	return _myBoard.placeShip(ship);
}

AI::AI(std::string name) :
	Player(name)
{
	// randomly place the 5 ships
}
bool AI::isHit()
{
	return Player::isHit(Position::Coordinates(0, 0)); // for testing
}