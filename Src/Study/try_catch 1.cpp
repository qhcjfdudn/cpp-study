#include <iostream>

using std::cout;
using std::endl;

double divide(double d, double v) {
	if (v == 0)
		throw "Divided by zero";	// throw�� std::terminate() ȣ��

	return d / v;
}

void terminateFunc() {
	cout << "terminated" << endl;	// terminate ���
	// exit(12);	// abort ��� exit code ���� ���� ����.
}

int main() {
	std::set_terminate(terminateFunc);
	// std::terminate();

	divide(10, 0);
}