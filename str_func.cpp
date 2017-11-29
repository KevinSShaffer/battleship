
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <locale>
#include <iostream>
#include "str_func.h"

std::vector<std::string> str_func::split(std::string sentence, char delimiter)
{
	std::vector<std::string> vec;

	// loop through each letter in sentence
	for (int front = 0, back = 0; back < sentence.length(); ++back, front = back)
	{
		// find next delimiter
		while (back < sentence.length() && sentence[back] != delimiter)
			back++;

		// add substring to vec
		if (back < sentence.length())
			vec.push_back(sentence.substr(front, back - front));
		else
			vec.push_back(sentence.substr(front, sentence.length() - front));
	}

	return vec;
}

std::string str_func::toLower(std::string str)
{
	std::locale loc;
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i], loc);

	return str; 
}

bool str_func::toBool(std::string str)
{
	bool b;
    std::istringstream is(toLower(str));

    is >> std::boolalpha >> b;

    return b;
}