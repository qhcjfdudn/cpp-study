#include <iostream>

class Parent {
public:
	virtual ~Parent() {}
};

class C1 : public Parent {};
class C2 : public Parent {
public:
	virtual ~C2() {}
};
class CC2 : public C2 {};

class D : public C1, public C2 {};

int main() {
	C1* c1 = new C1();
	C2* c2 = new C2();
	CC2* cc21 = new CC2();

	Parent* p1 = dynamic_cast<Parent*>(c2);		// up casting은 위험하지 않아, 성공
	Parent* p2 = dynamic_cast<Parent*>(cc21);	// 부모의 부모의 up casting. 성공

	C2* c22 = dynamic_cast<C2*>(c1);			// nullptr

	D d;
	C1* c12 = &d;								// 크로스 캐스팅 가능
	C2* c23 = dynamic_cast<C2*>(c12);			// 실제 객체가 d이기 때문에, 형제로 캐스팅이 된다.

	C2* c24 = dynamic_cast<C2*>(c1);			// nullptr. 실제 객체가 자식이 아니기 때문.
}