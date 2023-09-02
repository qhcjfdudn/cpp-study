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
	Child* c = dynamic_cast<Child*>(&p);	// 가리키는 객체가 실제 Child가 아닌 Parent라면?
	c->func();								// Undefined Behavior이다.
}

int main() {
	Parent* p = new Child();
	foo(*p);
	
	delete p;
}