
#include <string>
#include "player.h"
#include "game.h"

Game createGame(std::string, std::string);

int main()
{
	char again;
	do
	{
		Player winner;
		Game game = createGame("ships/player.csv", "ships/ai.csv");

		// loop until the game has a winner
		while (!game.hasWinner(winner))
		{
			game.takeTurn();
		}

		// ouput results
		std::cout << std::endl << winner.getName() << " has won!!!" << std::endl;

		std::cout << std::endl << "Would you like to play again?" << std::endl;
	} while ((std::cin >> again) && (again == 'Y' || again == 'y'));
}

Game createGame(std::string playerPath, std::string aiPath)
{
	try
	{
		return Game(playerPath, aiPath);
	}
	catch (UnableToInitialize ex)
	{
		std::cout << "Unable to create game from text files." << std::endl 
			<< "Issue with line: " << ex.GetCsvLine() << std::endl;

		return Game();
	}
	catch (...)
	{
		std::cout << "Unable to create game from text files." << std::endl;

		return Game();
	}
}