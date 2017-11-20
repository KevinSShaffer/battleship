
#include <string>
#include "player.h"
#include "game.h"


int main()
{
	Game game;

	while (!game.over())
	{
		game.takeTurn();
	}

	// ouput results
	// ask to play again
}