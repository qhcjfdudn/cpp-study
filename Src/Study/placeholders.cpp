#include <iostream>
#include <functional>

void func(int a, int b, int c) {
	std::cout << a << ", " << b << ", " << c << std::endl;
}

int main() {
	std::function<void(int, int, int)> f = 
		std::bind(
			func, 
			std::placeholders::_2, 
			std::placeholders::_3, 
			std::placeholders::_1
		);

	f(1, 2, 3);
}