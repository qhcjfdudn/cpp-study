#include <iostream>
using namespace std;

template<typename T>
class Animal {
public:
	Animal() : _age(3) {}

	int _age;
	void growl() const {
		static_cast<const T&>(*this).growl();

		cout << "breed: " << _age << endl;
	}
};

class Gromit : public Animal<Gromit> {
public:
	void growl() const {
		cout << "Gromit!!" << endl;
	}

};

class Baebsae : public Animal<Baebsae> {
public:
	void growl() const {
		cout << "Baeb~" << endl;
	}
};

template<typename T>
void growl(const Animal<T>& animal) {
	animal.growl();
}

int main() {
	Gromit g;
	Baebsae b;

	g.growl();	// Gromit!! <- 이렇게하면 CRTP가 아님. Gromit 타입의 growl()을 실행하는 것. Animal<Gromit> 타입의 growl()을 실행해야 함.
	growl(b);	// Baeb~
}