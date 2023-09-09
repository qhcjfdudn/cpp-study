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
	catch (int e) {	// func�� noexcept���� catch�� �ɷ����� �ʴ´�.
		cout << e << endl;
	}

	void (*fp1)() = func2;
//	void (*fp2)() noexcept = func2;	// error. noexcept�� noexcept(false)�� �Լ��� ������ �� ����.
}