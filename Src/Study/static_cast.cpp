#include <iostream>
using namespace std;

class ClassA {};
class ClassB {};
class ClassC {
public:
	ClassC(int num) {
		cout << num << endl;
	}
};
class ClassD {
public:
	explicit ClassD(int num) {
		cout << num << endl;
	}
	explicit operator bool() const {
		return true;
	}
};

enum class TypeA {
	A, B, C
};
enum TypeB {
	A, B, C
};

class Parent {};
class Child : public Parent {};

int main() {
	ClassA a;
//	ClassB* b = (ClassB*)&a;				// C Style Casting
//	ClassB* b = static_cast<ClassB*>(&a);	// ������ ������ �˷��ش�.

	float f = 1.1f;						
	int* i1 = (int*)&f;					// ������ ����
//	int* i2 = static_cast<int*>(&f);	// ������ ���� �˷���.

	// �Ʒ��� enum�� ����.
	TypeA t1 = static_cast<TypeA>(0);
	TypeB t2 = static_cast<TypeB>(t1);

	cout << static_cast<int>(t1) << endl;
	cout << static_cast<int>(t2) << endl;

	ClassC c1 = 1;
	ClassC c2 = ClassC(1);
	ClassC c3 = static_cast<ClassC>(1);

//	ClassD d1 = 1;						// error. explicit.
	ClassD d2 = static_cast<ClassD>(1);	// ��.
//	bool b1 = d2;						// error. explicit
	bool b3 = bool(d2);					// ��. �Լ� ��Ÿ�� ĳ����. ��ġ�� ������ ��Ÿ��.
	bool b2 = static_cast<bool>(d2);	// ��.

	Parent p;
	Child& c = static_cast<Child&>(p);	// �ٿ� ĳ���� - ������ ��.
										// ��� ���ٽ� ������ ���� �� ����.
										// static_cast ���� �ٸ� ������ �ʿ�
}