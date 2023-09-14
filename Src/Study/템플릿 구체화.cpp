#include <iostream>
#include "template_test_swap.h"

using std::cout;
using std::endl;

int main() {
	int x = 1, y = 2;
	swap<int>(x, y);	// 명시적 구체화 하지 않으면 컴파일 에러 발생
	cout << x << " " << y << endl;
}