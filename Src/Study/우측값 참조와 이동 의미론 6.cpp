#include <iostream>

using std::cout;
using std::endl;

void foo(int&) {
	cout << "int&" << endl;
}

void foo(int&&) {
	cout << "int&&" << endl;
}

template<typename T>
T&& move(T t) {
	return static_cast<T&&>(t);
}

int main() {
	foo(3); // int&&
	
	int num = 1;
	foo(num); // int&

	foo(std::move(num)); // int&&

	foo(static_cast<int&&>(num)); // int&&

	foo(move(num));	// int&&
}