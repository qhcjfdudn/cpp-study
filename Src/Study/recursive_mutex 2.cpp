#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::recursive_mutex m;

void goo() {
		std::lock_guard lg(m);
		std::cout << "goo()" << std::endl;
}

void foo() {
	std::lock_guard lg(m);
	std::cout << "foo()" << std::endl;

	goo();
}

int main() {
	foo();
}