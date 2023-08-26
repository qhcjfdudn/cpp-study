#include <iostream>
using namespace std;

class Base {
public:
	int get() {
		return 1;
	}
	virtual int get(int num) {
		return num;
	}
};

class Derived : public Base {
public:
//	using Base::get;	// 이게 없으면 부모의 get() 호출 불가.

	virtual int get(int num) override {
		return num + 1;
	}
};

int main() {
	Base b;
	b.get();

	Derived d;
//	d.get();	// 부모의 get()을 가려서 호출이 되지 않음.
}