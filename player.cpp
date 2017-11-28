
#include "player.h"

Player::Player(std::string name) :
	_name(name)
{
	_board = Board(10, 10, '~');
}
std::string Player::getName() const
{
	return _name;
}
Board Player::getBoard() const
{
	return _board;
}
std::vector<Ship> Player::getShips() const
{
	return _board.getShips();
}
bool Player::placeShip(const Ship ship)
{
	return _board.placeShip(ship);
}
bool Player::isHuman() const
{
	return _isHuman;
}
void Player::makeHuman()
{
	_isHuman = true;
}
void Player::makeAI()
{
	_isHuman = false;
}