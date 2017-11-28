#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

class UnableToReadFile
{
};

class UnableToInitialize
{
public:
	UnableToInitialize();
	UnableToInitialize(std::string);
	std::string GetCsvLine() const;
private:
	std::string _csvLine;
};
#endif