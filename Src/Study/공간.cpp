#include <iostream>
using namespace std;

void f() {
	static int a = 1;
	cout << a++ << endl;
}

int main() {
	for (int i = 1; i < 4; ++i) {
		static int j = 1;
		++j;
		cout << j << endl;	// 2, 3, 4
	}
	for (int i = 1; i < 4; ++i) 
		f();	// 1, 2, 3

	static int j = 1;
	cout << j << endl;	// 1
}