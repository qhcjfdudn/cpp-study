#include <iostream>
using namespace std;

class Character {
	int _health;
	int _power;
public:
	Character(int h, int p) : _health(h), _power(p) {}

	virtual void damaged(int power) {
		_health -= power;
	}

	void attack(Character& target) {
		target.damaged(_power);
	}
};

class Player : public Character {
public:
	Player(int h, int p) : Character(h, p) {}

	virtual void damaged(int power) override {
		Character::damaged(power);
		cout << "À¸¾Ç" << endl;
	}
};

class Monster : public Character {
public:
	using Character::Character;

	virtual void damaged(int power) override {
		Character::damaged(power);
		cout << "²Ï¾×" << endl;
	}
};

int main() {
	Player p1(200, 30);
	Monster m1(100, 50);

	p1.attack(m1);
	m1.attack(p1);
}