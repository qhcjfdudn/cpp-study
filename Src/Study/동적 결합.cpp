#include <iostream>
using namespace std;

class Animal {
public:
	virtual void eat() const {
		cout << "³È" << endl;
	}
};

class Dog : public Animal {
public:
	virtual void eat() const override {
		cout << "¸Û" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void eat() const override {
		cout << "³É" << endl;
	}
};

int main() {
	Dog d;
	Animal* animal = new Cat();
	animal->eat();	// ³É
}