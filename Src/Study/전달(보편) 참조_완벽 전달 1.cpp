#include <iostream>

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

int main() {
	int num1 = 2, num2 = 3;
	foo(num1, 4, num2);
	foo(2, 6, num1);
}