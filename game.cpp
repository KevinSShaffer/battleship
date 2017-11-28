
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
	for (int i = 0; i < NUM_SHIPS; i++)
	{
		while (!tryPlaceShip(_shipNames[i]))
		{
			std::cout << "Unable to place ship.  Please try again." << std::endl;
		}

		std::cout << std::endl << _player1->getBoard().getGrid().ToString() << std::endl;
	}

	// create player2 (AI)
	_player2 = new Player("HAL");
	// create ships													/* TODO: randomize */
	for (int i = 0; i < NUM_SHIPS; i++)
	{
		_player2->placeShip(Ship(_shipNames[i], Position::Coordinates(i, i), Position::Orientation::HORIZONTAL));
	}

	// determine who goes first										/* TODO: randomize */
	_first = _player1;
	_last = _player2;
}
Game::Game(Player* player1, Player* player2) :
	_player1(player1), _player2(player2)
{
	// determine who goes first										/* TODO: randomize */
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
bool Game::tryPlaceShip(ShipToken shipName)
{
	Ship ship = createShip(shipName);
	return _player1->placeShip(ship);
}
bool Game::over() const
{																	/* TODO: implement */
	return false;
}
void Game::takeTurn()
{

}