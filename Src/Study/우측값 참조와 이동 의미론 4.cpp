#include "MyString.h"
#include <iostream>

using std::cout;
using std::endl;

MyString makeString(const char* str) {
//	return std::move(MyString(str));	// 불필요.
	return MyString(str);
}

MyString makeString2(const char* str) {
	MyString s0("123");
	MyString s1("456");

	int a;
	std::cin >> a;
	if (a < 5) return s0;
	return s1;

	// return a < 5 ? s0 : s1; // 이 구문은 Copy Construct.
}

int main() {
	makeString("abc");
	makeString2("abc");
}