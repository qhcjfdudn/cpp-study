#include <iostream>

using std::cout;
using std::endl;

double divide(double d, double v) {
	if (v == 0)
		throw "Divided by zero";	// throw는 std::terminate() 호출

	return d / v;
}

void terminateFunc() {
	cout << "terminated" << endl;	// terminate 출력
	// exit(12);	// abort 대신 exit code 전달 종료 가능.
}

int main() {
	std::set_terminate(terminateFunc);
	// std::terminate();

	divide(10, 0);
}