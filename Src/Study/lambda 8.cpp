#include <iostream>

using std::cout;
using std::endl;

int main() {
	auto f = [](auto value) {
		return value;
		};

	cout << f(10) << endl;
	cout << f("Hello") << endl;
	cout << f(1.23f) << endl;
	// cout << f({ 1, 2, 3}) << endl; // auto이므로 initilizer는 안된다.

	// C++20버전
	auto f2 = []<typename T>(T value) {
		return value;
	};
}