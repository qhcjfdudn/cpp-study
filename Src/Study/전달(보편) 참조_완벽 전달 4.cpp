#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

void foo(int&, int&, int&) {}
void foo(int&, int&, int&&) {}
void foo(int&, int&&, int&) {}
void foo(int&, int&&, int&&) {}
void foo(int&&, int&, int&) {}
void foo(int&&, int&, int&&) {}
void foo(int&&, int&&, int&) {}
void foo(int&&, int&&, int&&) {}

template<typename T1, typename T2, typename T3>
void goo(T1&& num1, T2&& num2, T3&& num3) {
	cout << "T1: " << std::is_lvalue_reference_v<T1> << endl;
	cout << "T2: " << std::is_lvalue_reference_v<T2> << endl;
	cout << "T3: " << std::is_lvalue_reference_v<T3> << endl;
}

int main() {
	int num1 = 2, num2 = 3;

	goo(num1, 4, num2);
	cout << endl;
	goo(2, 3, num1);
}