#include <iostream>
#include "template_test_swap.h"

using std::cout;
using std::endl;

int main() {
	int x = 1, y = 2;
	swap<int>(x, y);	// ����� ��üȭ ���� ������ ������ ���� �߻�
	cout << x << " " << y << endl;
}