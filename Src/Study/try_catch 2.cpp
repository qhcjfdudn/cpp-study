#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
	virtual ~Parent() {}
};

class Child : public Parent {};

double divide(double d, double v) {
	if (v == 0)
		throw Child();

	return d / v;
}

int main() {
	try {
		divide(10, 0);
	}
	catch (const char* s) {
		cout << s << endl;
	}
	catch (Child& c) {	// try - catch �������� ���� ���� ������� �˻��ϱ� ������
						// ��ü���� Ŭ������ �� ���� �˻��ǵ��� ��ġ �ʿ�.
		cout << "Child" << endl;
	}
	catch (Parent&) {
		cout << "Parent" << endl;
	}
	catch (...) {

	}
}