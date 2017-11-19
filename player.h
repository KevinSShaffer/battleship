
#include <string>

class Player
{
private:
	std::string _name;
	Board _shipBoard;
	Board _shotsBoard;
public:
	Player(std::string);
	std::string getName() const;
	bool isHit(const Coordinates);
};