#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
	virtual ~Parent() {};
};

class Child : public Parent {
public:
	void func() {
		cout << "func" << endl;
	}
};

void foo(Parent& p) {
	Child* c = dynamic_cast<Child*>(&p);	// ����Ű�� ��ü�� ���� Child�� �ƴ� Parent���?
	c->func();								// Undefined Behavior�̴�.
}

int main() {
	Parent* p = new Child();
	foo(*p);
	
	delete p;
}