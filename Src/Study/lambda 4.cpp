#include <iostream>

using std::cout;
using std::endl;

int main() {
	int num1 = 10, num2 = 20;

	[=]() {	// [] �ȿ� =�� ������ ��� ������ ������ ĸ���Ѵ�.
		cout << num1 + num2 << endl;
	} ();

	[&]() {	// [] �ȿ� &�� ������ ��� ������ ������ ĸ���Ѵ�.
		num1 += 3;
		cout << num1 + num2 << endl;
	} ();

	[=, &num1]() {	// ��� ������ ������ ĸ���ϵ�, num1�� ������ ĸ���Ѵ�.
		num1 = 1;
		cout << num1 + num2 << endl;
	} ();

	[&, num1]() {	// ��� ������ ������ ĸ���ϵ�, num1�� ������ ĸ���Ѵ�.
		// num1 = 1; // error. ���� �Ұ�
		num2 = 4;
		cout << num1 + num2 << endl;
	} ();
}