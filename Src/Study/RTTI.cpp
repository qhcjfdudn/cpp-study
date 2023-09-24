#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
	virtual ~Parent() {}
};

class Child : public Parent {};

int main() {
	Parent pp;
	Parent* p = new Child();
	cout << typeid(*p).name() << endl;	// ���� �Լ��� ���ٸ� �������� 'Class Parent' ���
										// ���� �Լ���� �������� 'Class Child' ���

	Child* c = dynamic_cast<Child*>(p);
	if (c == nullptr) {
		cout << "c�� ���� ���̺��� �����Ǿ���!" << endl;
	}
}