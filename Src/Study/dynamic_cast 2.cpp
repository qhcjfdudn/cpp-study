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
	Child* c = dynamic_cast<Child*>(&p);	// p�� Ÿ���� down casting�� ���ٸ�, nullptr ��ȯ.
	if (c == nullptr) return;				// ��Ÿ�� ���߿� ������ ����ȯ�� ����.

	c->func();
}

void bar(Parent& p) {
	Child& c = dynamic_cast<Child&>(p);		// Child Ÿ���� �ƴ� ��� ��Ÿ�ӿ��� bad_cast �߻��Ѵ�.
	c.func();								// try-catch�� ���� �� ������ �̰� ������ ���.
}

int main() {
	Parent* p1 = new Child();
	Parent* p2 = new Parent();

	foo(*p1);	// func ���
	foo(*p2);	// ���	X

//	bar(*p2);	// ��Ÿ�ӿ��� bad_cast �߻��Ѵ�.

	delete p1;
	delete p2;

	Parent* p3 = new Child();	// up casting�� �Ϲ��� ����
	Parent* p4 = static_cast<Parent*>(new Child());	// up casting

//	Child* c3 = new Parent();	// down casting�� �Ϲ������� ���� �ʴ´�.
	Child* c4 = dynamic_cast<Child*>(new Parent());	// down	casting -> nullptr
}