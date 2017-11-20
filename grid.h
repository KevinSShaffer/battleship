#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>
#include "position.h"

class Grid
{
private:	
	std::vector< std::vector<char> > _vec;
	int _rows, _columns;
public:
	Grid();
	Grid(int rows, int cols);
	Grid(std::vector< std::vector<char> > vec);
	int getColumns() const;
	int getRows() const;
	std::string ToString();
	std::vector<char> operator [](const int row) const;
	bool mark(Position::Coordinates, char);
};
#endif