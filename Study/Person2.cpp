#include "Person2.h"
#include <iostream>

int Person2::si = 0;

Person2::Person2() {
	si++;
}

void Person2::print() {
	std::cout << si << std::endl;
}