#include <iostream>

using std::cout;
using std::endl;

class cException : public std::exception {
public:
	virtual const char* what() const override {
		return "Custom";
	}
};

double divide(double d, double v) {
	if (v == 0) {
		throw cException();
//		throw std::exception("Custom Message");
	}

	return d / v;
}

void func1() {
	try {
	divide(10, 0);
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}
}

void func0() {
	func1();
}

int main() {
	try {
		func0();
		cout << "main" << endl;
	}
	catch (const char* s) {
		cout << s << endl;
	}

	//std::logic_error l;
	//std::runtime_error r;
	//std::out_of_range o;
}