#include <iostream>
using namespace std;

class Animal {
public:
	virtual void eat() const {
		cout << "��" << endl;
	}
};

class Dog : public Animal {
public:
	virtual void eat() const override {
		cout << "��" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void eat() const override {
		cout << "��" << endl;
	}
};

int main() {
	Dog d;
	Animal* animal = new Cat();
	animal->eat();	// ��
}