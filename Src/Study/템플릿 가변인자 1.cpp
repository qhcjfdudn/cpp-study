#include <iostream>
#include <cstdarg>

using std::cout;
using std::endl;

// int sum(int count...) { // �Ʒ��� ����
int sum(int count, ...) {
	int result = 0;
	va_list args;
	va_start(args, count);	// 
	for (int i = 0; i < count; ++i) {
		result += va_arg(args, int);	// int�� size��ŭ ��� �����ؼ� �˷��� ��.
		cout << result << endl;
	}
	va_end(args);
	return result;
}

int main() {
	cout << sum(4, 1, 2, 3, 4) << endl;	// �Ķ���͵��� stack�� ���δ�. stack?
}