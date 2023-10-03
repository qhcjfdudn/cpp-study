#include <iostream>

using std::cout;
using std::endl;

int main() {
	int count = 4;
	auto f = [count]() mutable {
		return ++count;
	};

	// 함수의 모양만 보면, 캡쳐한 변수가 보이지 않아서
	// 모든 결과가 다 같을 것으로 예상된다. -> 실수가 발생할 수 있다.
	// 그래서 default는 const로 캡쳐를 변경할 수 없는 형태로 만들었다.
	cout << f() << endl;	// 5
	cout << f() << endl;	// 6
	cout << f() << endl;	// 7
}