#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

// callable

class Func {
public:
	int operator()(float value) {
		return value;
	}
};

int func(float value) {
	return value;
}

int main() {
	function<int(float)> f1 = Func();
	cout << f1(13.2f) << endl;

	function<int(float)> f2 =
		[](float value) {
			return value;
		};

	cout << f2(2.8f) << endl;

	function<int(float)> f3 = func;
	cout << f3(5.6f) << endl;
}