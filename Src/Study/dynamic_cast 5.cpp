#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
	virtual ~Parent() {}
};

class Child : public Parent {};

void foo(Child& c);

// dynamic_cast, static_cast 둘 다 사용해보기.
void foo(Parent& p) {
	if (dynamic_cast<Child*>(&p) != nullptr) {	// 실제 객체가 Parent가 아니라면
		Child* c = static_cast<Child*>(&p);
		foo(*c);
		return;
	}
	cout << "foo1" << endl;
}
void foo(Child& c) {
	cout << "foo2" << endl;
}

int main() {
	Parent* p = new Child();
	Parent* pp = new Parent();

	foo(*p);	// foo2
	foo(*pp);	// foo1
}