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
//	using Base::get;	// �̰� ������ �θ��� get() ȣ�� �Ұ�.

	virtual int get(int num) override {
		return num + 1;
	}
};

int main() {
	Base b;
	b.get();

	Derived d;
//	d.get();	// �θ��� get()�� ������ ȣ���� ���� ����.
}