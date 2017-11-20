


Board::Board(int x, int y)
{
	_grid = Grid(x, y);
}
std::Vector<Ship> Board::getShips() const
{
	return _ships;
}
std::Vector<Shot> Board::getShots() const
{
	return _shots;
}
bool Board::isHit(const Coordinate) const
{
	return true; // for testing;
}
void Board::placeShip(const Ship ship)
{
	// empty for testing
}
bool Board::isValidPlacement(Position::Orientation orientation, int x, int y, int length) const
{
	int max_x = _grid.getColumns();
	int may_y = _grid.getRows();
	length--;
	if (orientation == Position::HORIZONTAL)
		return x + length < max_x && y < max_y;
	else
		return x < max_x && y + length < max_y;
}