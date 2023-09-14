#include "template_test_swap.h"

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template
void swap<int>(int&, int&);