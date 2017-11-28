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
	void markGrid(Ship);
public:
	Board();
	Board(int, int);
	Board(int, int, char);
	std::vector<Ship> getShips() const;
	std::vector<Shot> getShots() const;
	Grid getGrid() const;
	bool isHit(Shot);
	bool placeShip(const Ship);
};
#endif