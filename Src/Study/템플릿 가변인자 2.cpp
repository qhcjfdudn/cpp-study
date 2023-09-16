#include <iostream>

using std::cout;
using std::endl;

template<typename T>
T sum(T value) {
	return value;
}

template<typename T, typename... Args>
T sum(T value, Args... args) {
	return value + sum(args...);
}

int main() {
	cout << sum(1, 2, 3, 4) << endl;
}