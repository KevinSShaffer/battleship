
#include "board.h"

Board::Board() :
	_grid(Grid(10, 10))
{
}
Board::Board(int x, int y)
{
	_grid = Grid(x, y);
}
std::vector<Ship> Board::getShips() const
{
	return _ships;
}
std::vector<Shot> Board::getShots() const
{
	return _shots;
}
bool Board::isHit(const Position::Coordinates) const
{
	return true; // for testing;
}
bool Board::placeShip(const Ship ship)
{
	// check for ship intersections

	int max_x = _grid.getColumns();
	int max_y = _grid.getRows();
	Position::Coordinates coordinates = ship.GetCoordinates();

	if (ship.getOrientation() == Position::HORIZONTAL &&
		coordinates.X + ship.getLength() - 1 < max_x && coordinates.Y < max_y) // is valid
	{
		_ships.push_back(ship);
		return true;
	}
	else if (coordinates.X < max_x && coordinates.Y + ship.getLength() - 1 < max_y)  // is valid
	{
		_ships.push_back(ship);
		return true;
	}
	else
	{
		return false;
	}
}