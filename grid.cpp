/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001        
*  HW#         :  2     
*  Due Date    :  Sep 12th, 2013
*  Description :  Grid object based on a 2d vector with added 
				  functionality such as ToString and Randomize.
********************************************************************/

#include "grid.h"
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

Grid::Grid(int rows, int cols) :
	_vec(rows, std::vector<int>(cols)), _rows(rows), _columns(cols)
{
	// seed a RNG with current date time
	srand(time(0));
}
Grid::Grid(int rows, int cols, int seed) :
	_vec(rows, std::vector<int>(cols)), _rows(rows), _columns(cols)
{
	srand(seed);	
}
Grid::Grid(std::vector< std::vector<int> > vec) :
	_vec(vec)
{
	srand(time(0));
}
int Grid::getColumns() const
{
	return _columns;
}
int Grid::getRows() const
{
	return _rows;
}
void Grid::Randomize()
{
	// determine 1/3 of the cells (rounded down)
	Randomize(_rows * _columns / 3);
}
void Grid::Randomize(const int numCellsToChange)
{
	int cellsChanged = 0;

	// loop until 1/3 of the cells are changed
	while (cellsChanged < numCellsToChange)
	{
		// randNum is a random number from 0 to (# of elements in grid) - 1
		// randRow is a random vector<int>
		// randRow is a random element in the vector<int>
		// location is a reference to the randomly selected integer in the grid
		int randNum = rand() % (_rows * _columns),
			randRow = randNum / _columns,
			randCol = randNum % _columns;
		int& location = _vec[randRow][randCol];

		// if the location hasn't already been set
		if (location == 0)
		{
			location = 1;
			cellsChanged++;
		}
	}	
}
std::string Grid::ToString()
{
	std::string output;

	// loop through the rows in the grid
	for (std::vector< std::vector<int> >::iterator it_x = _vec.begin();
		it_x != _vec.end();
		++it_x)
	{
		// add new line except on the first row
		if (it_x != _vec.begin())
			output.append("\n");

		// loop through the columns in the grid
		for (std::vector<int>::iterator it_y = it_x->begin();
			it_y != it_x->end();
			++it_y)
		{
			// add a space (except the first column) and the digit to ouput
			if (it_y != it_x->begin())
				output += " | ";

			output += *it_y + 48;
		}
	}

	return output;
}
Grid Grid::operator *(const Grid& grid2) const
{
	// if the grids aren't the same size
	// then return a blank grid
	// !!! THIS COULD BE IMPROVED !!!
	if (_rows != grid2.getRows() ||
		_columns != grid2.getColumns())
		return Grid(0, 0);

	// create new vector with same size as the other two
	std::vector< std::vector<int> > vec(_rows, std::vector<int>(_columns));

	// loop through all elements in the grids
	for(int x = 0; x < _rows; x++)
	{
		for (int y = 0; y < _columns; y++)
		{
			// assign result from the multiplication to the new vector 
			vec[x][y] = _vec[x][y] * grid2[x][y];
		}
	}

	return Grid(vec);
}
std::vector<int> Grid::operator [](const int row) const
{
	return _vec[row];
}