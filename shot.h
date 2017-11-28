#ifndef SHOT_H
#define SHOT_H
#include "position.h"

class Shot
{
private:
	Position::Coordinates _coordinates;
	bool _isHit;
public:
	Shot(Position::Coordinates);
	bool isHit() const;
	void makeHit();
	void makeMiss();
};
#endif