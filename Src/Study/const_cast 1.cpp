#include <iostream>
using std::cout;
using std::endl;

void func(const int& i) {
	int& j = const_cast<int&>(i);
	j = 10;
}

int main() {
	int i = 0;
	func(i);			// 함수의 시그니쳐만 보고
						// const로 값을 받을 것이라 보고 값 변경이 
						// 안될 거라 생각한다면 큰일.
	cout << i << endl;	// 값이 10으로 출력된다.

	const int i1 = 0;	// undefined behavior.
	func(i1);			// 컴파일러 따라서 어떻게 출력될지
	cout << i1 << endl;	// 알 수 없는 상황.
						
}