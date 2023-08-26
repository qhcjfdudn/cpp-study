#include <iostream>
using namespace std;

int main() {
	char c{ 14213 };	// 중괄호 초기화를
	int i = { 1.1f };	// Uniform Initialization이라 한다.
						// 현재 경우 "축소 변환"이 필요하다고
						// 컴파일 error.

	int i2 = 1;
	const int i3 = 3;
	char c1{ i2 };	// 컴파일 에러. 변수는 안된다.
	char c2{ i3 };	// ok. 상수는 됨.
}