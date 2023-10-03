#include <iostream>

using std::cout;
using std::endl;

struct Test {
	int num = 1;
	
	auto func() {
		int num = 3;
		return [&num]() {	// 메모리가 해제될 경우
			return num;		// 쓰레기 값 반환될 수 있다.
		};
	}

	auto func2() {
		return [num = num]() { // Initializer 캡쳐. C++14부터 가능
		// return [*this] { // C++17에서 가능
		// return [a = 1, b = std::string()] { // 이런 것도 가능
		// return [a = num * 20] // 별게 다 가능..
			return num;
		};
	}
};

int main() {
	Test* t = new Test();
	auto f = t->func();
	delete t;

	cout << f() << endl;	// garbage 값 출력
							// 캡쳐에서 참조를 전달했는데
							// 변수의 메모리가 해제되었기
							// 때문

							// 참조가 아닌 값으로 전달하면
							// 정상적으로 반환

	t = new Test();
	auto f2 = t->func2();

	cout << f2() << endl;

}