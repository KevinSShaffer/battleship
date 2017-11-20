#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game
{
private:
	Player* _player1;
	Player* _player2;
	Player* _first;
	Player* _last;
public:
	Game(Player*, Player*);
	~Game();
	bool over() const;
};
#endif