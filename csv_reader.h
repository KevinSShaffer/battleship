#ifndef CSV_READER_H
#define CSV_READER_H
#include <fstream>
#include <string>
#include <vector>

class CsvReader
{
private:
public:
	static std::vector<std::string> readLines(std::string, bool);
};
#endif