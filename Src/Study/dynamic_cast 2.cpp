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
	Child* c = dynamic_cast<Child*>(&p);	// p의 타입이 down casting과 같다면, nullptr 반환.
	if (c == nullptr) return;				// 런타임 도중에 안전한 형변환을 제공.

	c->func();
}

void bar(Parent& p) {
	Child& c = dynamic_cast<Child&>(p);		// Child 타입이 아닐 경우 런타임에서 bad_cast 발생한다.
	c.func();								// try-catch로 잡을 수 있지만 이게 편한지 고민.
}

int main() {
	Parent* p1 = new Child();
	Parent* p2 = new Parent();

	foo(*p1);	// func 출력
	foo(*p2);	// 출력	X

//	bar(*p2);	// 런타임에서 bad_cast 발생한다.

	delete p1;
	delete p2;

	Parent* p3 = new Child();	// up casting은 암묵적 가능
	Parent* p4 = static_cast<Parent*>(new Child());	// up casting

//	Child* c3 = new Parent();	// down casting은 암묵적으로 되지 않는다.
	Child* c4 = dynamic_cast<Child*>(new Parent());	// down	casting -> nullptr
}