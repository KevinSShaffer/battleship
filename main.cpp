
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
	for (int i = 0; i < NUM_SHIPS; i++)
	{
		int x, y, length, depth;
		Position::Orientation orientation;
		Position::Coordinates coordinates;

		do
		{
			x = getInput("Enter the x coordinate: ");
			y = getInput("Enter the y coordinate: ");
			coordinates = Position::Coordinates(x, y)
			length = getInput("Enter the length: ");
			orientation = getOrientation();
			Ship ship(coordinate, orientation, length, depth);
		} while (!player.placeShip(ship));
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
Position::Orientation getOrientation()
{
	char letter = '\0';
	do
	{
		cout << "Horizontal (h) or Verical (v) orientation: " << endl;
		cin >> letter;
		cin.clear();
		cin.ignore(256, '\n');
	} while (!letter || letter != 'h' && letter != 'H' && letter != 'v' && letter != 'V');

	return ((letter == 'h' || letter == 'H') ? Position::HORIZONTAL : Position::VERTICAL);
}