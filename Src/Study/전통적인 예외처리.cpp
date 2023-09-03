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
	
	freopen("input.txt", "r", stdout);	// 읽기인데 stdout;
	int ret = printf("%d", 10);

	cout << ret << endl;	// 객체로 묶인 형태는 그래도 쓰기 좋다.
	bool b = cout.fail();	// 하지만 번거롭기도 하다.
	

	double result;
	int code = divide(10, 20, result);
	if (code != -1) {	// 가능하나, 구리다.

	}
	else {}
}