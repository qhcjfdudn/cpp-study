#include <iostream>
#include <cstdarg>

using std::cout;
using std::endl;

// int sum(int count...) { // 아래와 같음
int sum(int count, ...) {
	int result = 0;
	va_list args;
	va_start(args, count);	// 
	for (int i = 0; i < count; ++i) {
		result += va_arg(args, int);	// int의 size만큼 계속 전진해서 알려줄 것.
		cout << result << endl;
	}
	va_end(args);
	return result;
}

int main() {
	cout << sum(4, 1, 2, 3, 4) << endl;	// 파라미터들이 stack에 쌓인다. stack?
}