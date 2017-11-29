#ifndef CSV_READER_H
#define CSV_READER_H
#include <fstream>
#include <string>
#include <vector>

using csv_lines = std::vector<std::string>;

class CsvReader
{
private:
public:
	static csv_lines readLines(std::string, bool);
};
#endif