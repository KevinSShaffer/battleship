#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "board.h"
#include "position.h"

class Player
{
private:
	std::string _name;
	Board _board;
	bool _isHuman = true;
	char _waterToken = '~';
public:
	Player(std::string);
	std::string getName() const;
	Board getBoard() const;
	std::vector<Ship> getShips() const;
	bool placeShip(const Ship);
	bool isHuman() const;
	void makeHuman();
	void makeAI();
	bool isHit(Shot);
	std::string boardToString(bool);
	bool isShipToken(char) const;
	bool hasLost() const;
};
#endif