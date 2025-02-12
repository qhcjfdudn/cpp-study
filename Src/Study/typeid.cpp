#include <iostream>
using namespace std;

class GrandParent {
public:
	virtual void func() {
		cout << "func GrandParent" << endl;
	}
};
class Parent : public GrandParent {};
class Child : public Parent {
public:
	virtual void func() override {
		cout << "func Child" << endl;
	}
};

int main() {
	GrandParent g;
	Parent p;
	Child c;
	cout << typeid(g).name() << endl; // class GrandParent
	cout << typeid(p).name() << endl; // class Parent
	cout << typeid(c).name() << endl; // class Child
	
	if (typeid(c).before(typeid(g))) // typeid(me).before(typeid(you))
	{
		cout << typeid(g).name() << " is super class of " << typeid(c).name() << endl;
		// class GrandParent is super class of class Child
	}
}