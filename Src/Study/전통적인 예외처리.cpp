#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int divide(double d, double v, double& result) {
	if (v == 0) return -1;
	
	result = d / v;

	return 0;
}

int main() {
	
	freopen("input.txt", "r", stdout);	// �б��ε� stdout;
	int ret = printf("%d", 10);

	cout << ret << endl;	// ��ü�� ���� ���´� �׷��� ���� ����.
	bool b = cout.fail();	// ������ ���ŷӱ⵵ �ϴ�.
	

	double result;
	int code = divide(10, 20, result);
	if (code != -1) {	// �����ϳ�, ������.

	}
	else {}
}