#ifndef SHOT_H
#define SHOT_H
#include <locale>
#include "position.h"

class Shot : public Position::Coordinates
{
private:
	bool _isHit;
public:
	Shot(int, int);
	Shot(char, int); // assumes 'C2' format where the digit is the index + 1
	bool isHit() const;
	void makeHit();
	void makeMiss();
};
#endif