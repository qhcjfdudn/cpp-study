#include <iostream>
using namespace std;

template<typename T>
class GameObject {
	int _objectId;
public:
	GameObject(int oid = 0) : _objectId(oid) {}

	int GetObjectId() const {
		return _objectId;
	}
	void SetObjectId(int oid) {
		_objectId = oid;
	}
};

template<typename T>
class Monster : public GameObject<Monster<T>> {
	int _hp;

public:
	Monster() : _hp(100) {}

	int GetHP() const {
		return _hp;
	}

	void Growl() const {
		static_cast<const T&>(*this).Growl();
	}
};

class Gromit : public Monster<Gromit> {
public:
	void Growl() const {
		cout << "Gromit!!" << endl;
	}
};

class Baebsae : public Monster<Baebsae> {
public:
	void Growl() const {
		cout << "Baeb~" << endl;
	}
};

template<typename T>
void Growl(const Monster<T>& monster) {
	monster.Growl();
}

int main() {
	Gromit g;

	// 상속했으나 다형성이 필요 없는 경우는 객체지향적으로 메서드를 호출하면 된다.
	g.SetObjectId(3);
	cout << "gromit objectId: " << g.GetObjectId() << endl;
	cout << "HP: " << g.GetHP() << endl;

	// 다형성이 필요한 경우엔 함수를 호출한다.
	Baebsae b;

	Growl(g);	// Gromit!!
	Growl(b);	// Baeb~
}