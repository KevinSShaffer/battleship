
#include "board.h"

Board::Board() :
	_grid(Grid(10, 10))
{
}
Board::Board(int x, int y)
{
	_grid = Grid(x, y);
}
Board::Board(int x, int y, char c)
{
	_grid = Grid(x, y, c);
}
std::vector<Ship> Board::getShips() const
{
	return _ships;
}
std::vector<Shot> Board::getShots() const
{
	return _shots;
}
Grid Board::getGrid() const
{
	return _grid;
}
bool Board::isHit(const Position::Coordinates) const
{
	return true; // for testing;
}
void Board::markGrid(Ship ship)
{
	std::vector<Position::Coordinates> area = ship.getArea();

	for (unsigned int i = 0; i < ship.getLength(); i++)
	{
		_grid.mark(area[i], ship.getIdentifier());
	}
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
		markGrid(ship);
		_ships.push_back(ship);
		return true;
	}
	else if (coordinates.X < max_x && coordinates.Y + ship.getLength() - 1 < max_y)  // is valid
	{
		markGrid(ship);
		_ships.push_back(ship);
		return true;
	}
	else
	{
		return false;
	}
}