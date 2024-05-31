#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void goo() {
	try {
		std::lock_guard lg(m);
		std::cout << "goo()" << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		// resource deadlock would occur: resource deadlock would occur
	}
}

void foo() {
	std::lock_guard lg(m);
	std::cout << "foo()" << std::endl;

	goo();
}

int main() {
	foo();
}