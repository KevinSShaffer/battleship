#ifndef STR_FUNC_H
#define STR_FUNC_H 
#include <vector>
#include <string>

using words = std::vector<std::string>;

namespace str_func
{
	words split(std::string, char);
	std::string toLower(std::string);
	bool toBool(std::string);
}
#endif