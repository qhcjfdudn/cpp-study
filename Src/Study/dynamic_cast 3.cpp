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

	Parent* p1 = dynamic_cast<Parent*>(c2);		// up casting�� �������� �ʾ�, ����
	Parent* p2 = dynamic_cast<Parent*>(cc21);	// �θ��� �θ��� up casting. ����

	C2* c22 = dynamic_cast<C2*>(c1);			// nullptr

	D d;
	C1* c12 = &d;								// ũ�ν� ĳ���� ����
	C2* c23 = dynamic_cast<C2*>(c12);			// ���� ��ü�� d�̱� ������, ������ ĳ������ �ȴ�.

	C2* c24 = dynamic_cast<C2*>(c1);			// nullptr. ���� ��ü�� �ڽ��� �ƴϱ� ����.
}