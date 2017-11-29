#ifndef SHOT_H
#define SHOT_H
#include <string>
#include <sstream>
#include "position.h"

class Shot : public Position::Coordinates
{
private:
	bool _isHit;
public:
	Shot(int, int);
	bool isHit() const;
	void makeHit();
	void makeMiss();
	std::string toString() const;
};
#endif