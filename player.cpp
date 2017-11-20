
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
	return _theirBoard.isHit(shot);
}
void Board::placeShip(const Ship ship)
{
	_myBoard.placeShip(ship);
}