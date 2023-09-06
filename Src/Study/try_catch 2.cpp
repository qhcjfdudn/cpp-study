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
	catch (Child& c) {	// try - catch 구문에서 먼저 나온 순서대로 검색하기 때문에
						// 구체적인 클래스가 더 먼저 검색되도록 배치 필요.
		cout << "Child" << endl;
	}
	catch (Parent&) {
		cout << "Parent" << endl;
	}
	catch (...) {

	}
}