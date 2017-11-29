
#include "csv_reader.h"

csv_lines CsvReader::readLines(std::string filePath, bool omitHeader)
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream fs;
	fs.open(filePath.c_str());

	while (std::getline(fs, line))
	{
		if (omitHeader)
			omitHeader = false;
		else
			lines.push_back(line);
	}

	return lines;
}