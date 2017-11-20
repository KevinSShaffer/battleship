#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>
#endif

class Grid
{
private:	
	std::vector< std::vector<int> > _vec;
	int _rows, _columns;
public:
	Grid(int rows, int cols);
	Grid(int rows, int cols, int seed);
	Grid(std::vector< std::vector<int> > vec);
	int getColumns() const;
	int getRows() const;
	void Randomize();
	void Randomize(const int numCellsToChange);
	std::string ToString();
	Grid operator *(const Grid& grid2) const;
	std::vector<int> operator [](const int row) const;
};