#include <iostream>

using std::cout;
using std::endl;

constexpr int fibo(int n) {
	return n <= 1 ? n : fibo(n - 2) + fibo(n - 1);
}

template<int N>
void func() {
	cout << N << endl;
}
int main() {
	constexpr int value = fibo(50);

	// 아래 두 구문에서 컴파일 에러가 없다는 건,
	// 컴파일 타임에 value가 값으로 치환이 된다는 것을
	// 보장 받는다는 의미이다.
	int arr[value];
	func<value>();

	int num = 10;
	// constexpr int value2 = fibo(num); // error.
	// 식에 상수 값이 있어야 하는데, 변수가 전달되면
	// 컴파일 타임에 계산이 될지 보장할 수 없다.

	// void f(constexpr int a) {}	// error. 매개변수의 지정자가 잘못되었습니다.

}