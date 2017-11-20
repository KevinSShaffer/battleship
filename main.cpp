
#include <iostream>
#include <string>
#include "player.h"
#include "game.h"

const int NUM_SHIPS = 5;

int getInput(std::string);
Position::Orientation getOrientation();

int main()
{
	// create player1
	std::string name;

	do
	{
		std::cout << "Input your name: " << std::endl;
	} while (!(std::cin >> name));

	Player player(name);

	// have player1 add ships
	for (int i = 0; i < NUM_SHIPS; i++)
	{
		bool placed;
		do
		{
			int x, y, length, depth;
			Position::Orientation orientation;

			x = getInput("Enter the x coordinate: ");
			y = getInput("Enter the y coordinate: ");
			Position::Coordinates coordinates = Position::Coordinates(x, y);
			length = getInput("Enter the length: "); // this should be "Pick a ship" instead
			orientation = getOrientation();
			Ship ship(coordinates, orientation, length);
			placed = player.placeShip(ship);
		} while (!placed);
	}

	// create player2 (AI)
	Player ai("HAL");

	// create game
	Game game(&player, &ai);

	while (!game.over())
	{
		// generate players' shots
	}

	// ouput results
	// ask to play again
}
int getInput(std::string question)
{
	int value = -1;

	// loop until user provides valid integer input 
	while (value < 0)
	{
		std::cout << question << std::endl;
		std::cin >> value;
		std::cin.clear();
		std::cin.ignore(256,'\n');
	}

	return value;
}
Position::Orientation getOrientation()
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