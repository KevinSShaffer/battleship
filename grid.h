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
	Grid(int, int);
	Grid(int, int, char);
	Grid(std::vector< std::vector<char> >);
	int getColumns() const;
	int getRows() const;
	std::string toString();
	std::string toString(std::string);
	std::vector<char> operator [](const int) const;
	bool mark(Position::Coordinates, char);
};
#endif