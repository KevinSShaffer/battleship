
#include "game.h"

Game::Game(Player* player1, Player* player2) :
	_player1(player1), _player2(player2)
{
	// determine who goes first
	_first = player1;
	_last = player2;
}
Game::~Game()
{
	delete(_player1);
	delete(_player2);
	delete(_first);
	delete(_last);
}
bool Game::over() const
{
	return false; // for testing
}