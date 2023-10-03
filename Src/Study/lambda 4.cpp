#include <iostream>

using std::cout;
using std::endl;

int main() {
	int num1 = 10, num2 = 20;

	[=]() {	// [] 안에 =를 넣으면 모든 변수를 값으로 캡쳐한다.
		cout << num1 + num2 << endl;
	} ();

	[&]() {	// [] 안에 &를 넣으면 모든 변수를 참조로 캡쳐한다.
		num1 += 3;
		cout << num1 + num2 << endl;
	} ();

	[=, &num1]() {	// 모든 변수를 값으로 캡쳐하되, num1은 참조로 캡쳐한다.
		num1 = 1;
		cout << num1 + num2 << endl;
	} ();

	[&, num1]() {	// 모든 변수를 참조로 캡쳐하되, num1은 값으로 캡쳐한다.
		// num1 = 1; // error. 수정 불가
		num2 = 4;
		cout << num1 + num2 << endl;
	} ();
}