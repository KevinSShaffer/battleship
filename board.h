
#include <vector>
#include "ship.h"

class Board 
{
private:
	std::Vector<Ship> _ships;
	std::Vector<Shot> _shots;
	Grid _grid;
public:
	Board(int, int);
	std::Vector<Ship> getShips() const;
	std::Vector<Shot> getShots() const;
	bool isHit(const Coordinates) const;
	void placeShip(const Ship);
	bool isValidPlacement(Position::Orientation, int, int, int) const;
};