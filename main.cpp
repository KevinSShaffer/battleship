
#include <iostream>
#include <string>

const int NUM_SHIPS = 5;

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
	int x, y, length, depth;
	Position::Orientation orientation;

	for (int i = 0; i < NUM_SHIPS; i++)
	{
		do
		{
			x = getInput("Enter the x coordinate: ");
			y = getInput("Enter the y coordinate: ");
			length = getInput("Enter the length: ");
			depth = getInput("Enter the dive depth in meters: ");
			orientation = getOrientation();
		} while (!isValid(orientation, x, y, length, grid.getRows(), grid.getColumns()));

		Ship ship(Position::Coordinates(x, y), orientation, length, depth);
		player.placeShip(ship);
	}
	
	// create player2 (AI)
	// create game
	// determine who goes first
	// get player shots
	// before/after each player shot, generate AI shot
	// check for winner
	// loop until winner
	// ouput results
	// ask to play again
}
int getInput(string question)
{
	int value = -1;

	// loop until user provides valid integer input 
	while (value < 0)
	{
		cout << question << endl;
		cin >> value;
		cin.clear();
		cin.ignore(256,'\n');
	}

	return value;
}