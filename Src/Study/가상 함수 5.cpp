#include <iostream>
using namespace std;

class Character {
public:
	int num;
};

class Player : public Character {
private:
	using Character::num;
};