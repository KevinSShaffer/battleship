
#include "exceptions.h"
#include <string>

UnableToInitialize::UnableToInitialize()
{
}

UnableToInitialize::UnableToInitialize(std::string csvLine)
{
	_csvLine = csvLine;
}

std::string UnableToInitialize::GetCsvLine() const
{
	return _csvLine;
}