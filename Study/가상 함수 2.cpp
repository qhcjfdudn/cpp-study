#include <iostream>
using namespace std;

class Character {
public:
	virtual ~Character() {}
};

class Player : public Character {
	virtual ~Player() {
		cout << "~Player" << endl;
	}
};

int main() {
	Character* c = new Player();
	delete c;	// ~Player
	// virtual이 없을 경우, 부모의 소멸자 호출.
}