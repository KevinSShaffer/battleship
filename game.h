#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.h"

class Game
{
private:
	const static int NUM_SHIPS = 5;
	const ShipToken _shipNames[NUM_SHIPS] = { "Carrier", 5, 'R',
		"Battleship", 4, 'B', 
		"Cruiser", 3, 'C',
		"Submarine", 3, 'U',
		"Destroyer", 2, 'D' };
	Player* _player1;
	Player* _player2;
	Player* _first;
	Player* _last;
	int getInput(std::string);
	Position::Orientation getOrientation();
	Ship createShip(ShipToken);
	bool tryPlaceShip(ShipToken);
	void takeTurn(Player*, Player*);
	void takeAiTurn(Player*, Player*);
public:
	Game();
	Game(Player*, Player*);
	~Game();
	void takeTurn();
	bool over() const;
};
#endif