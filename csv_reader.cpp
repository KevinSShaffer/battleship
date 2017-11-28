
#include "csv_reader.h"

std::vector<std::string> CsvReader::readLines(std::string filePath, bool omitHeader)
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream fs;
	fs.open(filePath.c_str());

	while (std::getline(fs, line))
	{
		lines.push_back(line);
	}

	return lines;
}