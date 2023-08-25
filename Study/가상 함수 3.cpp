#include <iostream>
using namespace std;

class Base {
public:
	virtual Base* get() {	// 반환형이 Base*
		return nullptr;
	}
	virtual Base& get2() {	// 반환형이 Base&
		return ;
	}
};

class Derived : public Base {
public:
	virtual Derived* get() override {	// override 가능
		return nullptr;
	}
	virtual Derived& get2() override {	// override 가능
		return ;
	}
};

int main() {
	Base b;
	b.get();

	Derived d;
	d.get();
}