#include <iostream>
using namespace std;

class Base {
public:
	virtual Base* get() {	// ��ȯ���� Base*
		return nullptr;
	}
	virtual Base& get2() {	// ��ȯ���� Base&
		return ;
	}
};

class Derived : public Base {
public:
	virtual Derived* get() override {	// override ����
		return nullptr;
	}
	virtual Derived& get2() override {	// override ����
		return ;
	}
};

int main() {
	Base b;
	b.get();

	Derived d;
	d.get();
}