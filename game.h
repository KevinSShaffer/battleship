#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "player.h"
#include "csv_reader.h"

class Game
{
private:
	const static int NUM_SHIPS = 5;
	const ShipToken _shipNames[NUM_SHIPS] = { "Carrier", 5, 'r',
		"Battleship", 4, 'b', 
		"Cruiser", 3, 'c',
		"Submarine", 3, 'u',
		"Destroyer", 2, 'd' };
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
	Game(std::string, std::string);
	Game(Player*, Player*);
	~Game();
	void takeTurn();
	bool hasWinner(Player&);
};
#endif