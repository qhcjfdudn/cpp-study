#include <iostream>

using std::cout;
using std::endl;

class Test {
private:
	std::string msg;
public:
	Test(const std::string& msg) : msg(msg) {}
	~Test() {
		cout << msg << endl;
	}
};

double divide(double d, double v) {

	Test t("divide");
	if (v == 0)
		throw "divided by zero";

	return d / v;
}

void func1() {
	Test t("func1");
	divide(10, 0);
	cout << "func1()" << endl;
}

void func0() {
	Test t("func0");
	func1();
	cout << "func0()" << endl;
}

int main() {
	try {
		func0();
		cout << "main" << endl;
	}
	catch (const char* s) {
		cout << s << endl;
	}
}