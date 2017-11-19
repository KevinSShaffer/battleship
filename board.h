
#include <vector>
#include "ship.h"

class Board 
{
private:
	std::Vector<Ship> _ships;
	std::Vector<Coordinates> _incomingShots;
	std::Vector<Coordinates> _outgoingShots;
	Grid _grid;
public:
	Board(int, int);
	std::Vector<Ship> getShips() const;
	std::Vector<Shot> getIncomingShots() const;
	std::Vector<Shot> getOutgoingingShots() const;
	bool isHit(const Coordinates) const;
	void placeShitp(const Ship);
};