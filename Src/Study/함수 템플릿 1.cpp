#include <iostream>

using std::cout;
using std::endl;

// template<class T> classµµ °¡´É. 
template<typename T>
void _swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int i1 = 2, i2 = 3;
	float f1 = 1.0f, f2 = 3.5f;
	char c1 = 'a', c2 = 'z';

	_swap<int>(i1, i2);
	_swap(f1, f2);
	_swap(c1, c2);

	cout << i1 << " " << i2 << endl;
	cout << f1 << " " << f2 << endl;
	cout << c1 << " " << c2 << endl;
}