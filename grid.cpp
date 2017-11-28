/********************************************************************
*  Name        :  Kevin Shaffer
*  Student ID  :  106069743
*  Class       :  CSCI 2312-001      
*  Due Date    :  Sep 12th, 2013
*  Description :  Grid object based on a 2d vector with added 
				  functionality such as ToString and Randomize.
********************************************************************/

#include "grid.h"

Grid::Grid() :
	_vec(10, std::vector<char>(10, ' ')), _rows(10), _columns(10)
{
}
Grid::Grid(int rows, int cols) :
	_vec(rows, std::vector<char>(cols, ' ')), _rows(rows), _columns(cols)
{
}
Grid::Grid(int rows, int cols, char c) :
	_vec(rows, std::vector<char>(cols, c)), _rows(rows), _columns(cols)
{
}
Grid::Grid(std::vector< std::vector<char> > vec) :
	_vec(vec)
{
}
int Grid::getColumns() const
{
	return _columns;
}
int Grid::getRows() const
{
	return _rows;
}
std::string Grid::ToString()
{
	std::string output;

	// loop through the rows in the grid
	for (std::vector< std::vector<char> >::iterator it_x = _vec.begin();
		it_x != _vec.end();
		++it_x)
	{
		// add new line except on the first row
		if (it_x != _vec.begin())
			output.append("\n");

		// loop through the columns in the grid
		for (std::vector<char>::iterator it_y = it_x->begin();
			it_y != it_x->end();
			++it_y)
		{
			// add a space (except the first column) and the digit to ouput
			if (it_y != it_x->begin())
				//output += " | ";
				output += " ";

			output += *it_y;
		}
	}

	return output;
}
std::vector<char> Grid::operator [](const int row) const
{
	return _vec[row];
}
bool Grid::mark(Position::Coordinates coordinates, char c)
{
	if (coordinates.X < 0 || coordinates.X >= _vec.size() ||
		coordinates.Y < 0 || coordinates.Y >= _vec.size())
		return false;
	else
	{
		_vec[coordinates.Y][coordinates.X] = c;
		return true;
	}
}