
#include <string>

class Player
{
private:
	std::string _name;
	Board _myBoard;
	Board _theirBoard;
public:
	Player(std::string);
	std::string getName() const;
	bool isHit(const Coordinates);
	void placeShip(const Ship);
};