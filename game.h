#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.h"

struct ShipLength
{
	std::string name;
	int length;
};
class Game
{
private:
	const ShipLength _shipNames[5] = { "Carrier", 5, "Battleship", 4, "Cruiser", 3, "Submarine", 3, "Destroyer", 2 };
	Player* _player1;
	Player* _player2;
	Player* _first;
	Player* _last;
	int getInput(std::string);
	Position::Orientation getOrientation();
	Ship createShip(ShipLength);
	void outputPossibleShips();
public:
	Game();
	Game(Player*, Player*);
	~Game();
	void takeTurn();
	bool over() const;
};
#endif