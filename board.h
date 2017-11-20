#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "grid.h"
#include "shot.h"
#include "ship.h"

class Board 
{
private:
	std::vector<Ship> _ships;
	std::vector<Shot> _shots;
	Grid _grid;
public:
	Board();
	Board(int, int);
	std::vector<Ship> getShips() const;
	std::vector<Shot> getShots() const;
	bool isHit(const Position::Coordinates) const;
	bool placeShip(const Ship);
};
#endif