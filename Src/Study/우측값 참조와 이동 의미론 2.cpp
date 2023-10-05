#include <iostream>

using std::cout;
using std::endl;

int main() {
	int num1 = 3, num2 = 4;
	int& ref1 = num1;
	int& ref2 = num2;

	ref1 = std::move(ref2); // 이게 왜 되지???

	ref1 = 3;	// 이게 왜 되지??????

	cout << ref1 << endl; // 3
}