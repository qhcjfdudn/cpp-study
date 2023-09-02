#include <iostream>
using std::cout;
using std::endl;

void func(const int& i) {
	int& j = const_cast<int&>(i);
	j = 10;
}

int main() {
	int i = 0;
	func(i);			// 인자가 const인 것을 전달했으나
	cout << i << endl;	// 값이 10으로 출력된다.

	const int i1 = 0;
	func(i1);			// undefined behavior.
	cout << i1 << endl;	// 컴파일러 따라서 어떻게 출력될지
						// 알 수 없는 상황
}