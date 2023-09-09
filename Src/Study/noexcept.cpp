#include <iostream>

using std::cout;
using std::endl;

void func1() noexcept {}
void func2() {}

int main() noexcept(noexcept(func1()) && noexcept(func2())) {
	try {
		func1();
		func2();
	}
	catch (int e) {	// func가 noexcept여서 catch로 걸러지지 않는다.
		cout << e << endl;
	}

	void (*fp1)() = func2;
//	void (*fp2)() noexcept = func2;	// error. noexcept에 noexcept(false)인 함수를 대입할 수 없다.
}