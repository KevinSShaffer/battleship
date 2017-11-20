


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