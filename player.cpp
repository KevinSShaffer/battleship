
#include "player.h"

Player::Player() :
	_name("")
{
}
Player::Player(std::string name) :
	_name(name)
{
	_board = Board(10, 10);
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
bool Player::isHit(Shot shot)
{
	return _board.isHit(shot);
}
std::string Player::boardToString(bool forOpponent)
{
	std::string output = _board/*.getGrid()*/.toString();

	// hide ship tokens as water
	if (forOpponent)
	{
		for (int i = 0; i < output.size(); i++)
		{
			if (isShipToken(output[i]))
				output[i] = _waterToken;
		}
	}

	return output;
}
bool Player::isShipToken(char c) const
{
	for (int i = 0; i < _board.getShips().size(); i++)
	{
		if (c == _board.getShips()[i].getIdentifier())
			return true;
	}

	return false;
}
bool Player::hasLost() const
{
	for (int i = 0; i < _board.getShips().size(); i++)
		if (!_board.getShips()[i].isSunk())
			return false;

	return true;
}