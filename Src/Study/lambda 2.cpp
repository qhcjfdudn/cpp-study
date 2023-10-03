#include <iostream>

using std::cout;
using std::endl;

class Func {
public:
	int value;
	void operator() () const {	// lambda의 기본은 함수에 전달되는 this가 const이다.
		// value = 2; // error. this가 const이기 때문.
 		cout << "value: " << value << endl;
	}
};

class Func2 {
public:
	int value;
	void operator() () {	// mutable을 사용할 경우 const가 빠져, 멤버 변경이 가능하다.
		value = 2;
		cout << "value: " << value << endl;
	}
};

int main() {
	int value = 10;
	auto func = [value]() {
		// value = 20; // 수정 불가능.
		cout << "value: " << value << endl;
	};

	// lambda의 실제 구현은 펑터이다. 펑터의 문법적 설탕이다.
	Func func1;

	// 캡쳐는 아래와 같다.
	func1.value = 20;

	func();
	func1();

	// 캡쳐한 변수를 수정하기 위해 mutable 사용
	auto func2 = [value]() mutable {
		value = 5;
		cout << "value: " << value << endl;
	};
	
	Func2 func3;
}