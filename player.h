#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "board.h"
#include "position.h"

class Player
{
private:
	std::string _name;
	Board _myBoard;
	Board _theirBoard;
public:
	Player(std::string);
	std::string getName() const;
	bool isHit(const Position::Coordinates);
	bool placeShip(const Ship);
};

class AI : public Player
{
public:
	AI(std::string);
	bool isHit();
};
#endif