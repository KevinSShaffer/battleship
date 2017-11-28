
#include "board.h"

Board::Board() :
	_grid(Grid(10, 10))
{
}
Board::Board(int x, int y)
{
	_grid = Grid(x, y, _waterToken);
}
Board::Board(int x, int y, char c) :
	_waterToken(c)
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
bool Board::isHit(Shot shot)
{
	if (shot.Y < 0 || shot.Y >= _grid.getRows() ||
		shot.X < 0 || shot.X >= _grid.getColumns())
	{
		return false;
	}
	else if (_grid[shot.Y][shot.X] == _hit ||
		_grid[shot.Y][shot.X] == _miss)
	{
		return _grid[shot.Y][shot.X] == _hit;
	}
	else
	{
		_shots.push_back(shot);

		// check if the shot hits any of the ships
		for (int i = 0; i < _ships.size(); i++)
		{
			if (_ships[i].isHit(shot))
			{
				shot.makeHit();
				_grid.mark(shot, _hit);
				return true;
			}
		}

		shot.makeMiss();
		_grid.mark(shot, _miss);
		return false;
	}
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
	// check for ship collision with other placed ships
	for (int i = 0; i < _ships.size(); i++)
		if (_ships[i].isCollision(ship))
			return false;

	// check if ship fits on board
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
bool Board::tryGetShip(Position::Coordinates coordinates, Ship& ship) const
{
	for (int i = 0; i < _ships.size(); i++)
	{
		std::vector<Position::Coordinates> area = _ships[i].getArea();

		for (int j = 0; j < area.size(); j++)
		{
			if (coordinates == area[j])
			{
				ship = _ships.at(i);
				return true;
			}
		}
	}

	return false;
}
bool Board::hasBeenShot(Position::Coordinates coordinates) const
{
	return _grid[coordinates.Y][coordinates.X] == _hit ||
		_grid[coordinates.Y][coordinates.X] == _miss;
}