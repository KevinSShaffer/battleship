
#include "game.h"

Game::Game()
{
	// create player1
	std::string name;

	do
	{
		std::cout << "Input your name: " << std::endl;
	} while (!(std::cin >> name));

	_player1 = new Player(name);

	// have player1 add ships
	for (int i = 0; i < 5; i++)
	{
		bool placed;
		do
		{
			Ship ship = createShip(_shipNames[i]);
			placed = _player1->placeShip(ship);
		} while (!placed);

		std::cout << std::endl << _player1->getBoard().getGrid().ToString() << std::endl;
	}

	// create player2 (AI)
	_player2 = new Player("HAL");
	// create ships

	// determine who goes first
	_first = _player1;
	_last = _player2;
}
Game::Game(Player* player1, Player* player2) :
	_player1(player1), _player2(player2)
{
	// TODO
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
int Game::getInput(std::string question)
{
	int value = -1;

	// loop until user provides valid integer input 
	while (value < 0)
	{
		std::cout << question << std::endl;
		std::cin >> value;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	return value;
}
Position::Orientation Game::getOrientation()
{
	char letter = '\0';
	do
	{
		std::cout << "Horizontal (h) or Verical (v) orientation: " << std::endl;
		std::cin >> letter;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	} while (!letter || letter != 'h' && letter != 'H' && letter != 'v' && letter != 'V');

	return ((letter == 'h' || letter == 'H') ? Position::HORIZONTAL : Position::VERTICAL);
}
Ship Game::createShip(ShipToken token)
{
	std::cout << std::endl << token.name << ":" << std::endl << std::endl;
	int x = getInput("Enter the x coordinate: ");
	int y = getInput("Enter the y coordinate: ");
	Position::Coordinates coordinates(x, y);
	Position::Orientation orientation = getOrientation();
	return Ship(token, coordinates, orientation);
}
bool Game::over() const
{
	return false; // for testing
}
void Game::takeTurn()
{

}