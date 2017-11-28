
#include <string>
#include "player.h"
#include "game.h"


int main()
{
	char again;
	do
	{
		Game game;
		Player winner;

		// loop until the game has a winner
		while (!game.hasWinner(winner))
		{
			game.takeTurn();
		}

		// ouput results
		std::cout << winner.getName() << " has won!!!" << std::endl;

		std::cout << "Would you like to play again?" << std::endl;
	} while ((std::cin >> again) && (again == 'Y' || again == 'y'));
}