#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

int main() {
	int num0 = 10;
	int& num1 = num0;
	// int& num1 = 10; // error.
	int&& num2 = 10;

	const int& num3 = 10;	// 이것도 되긴 함.

	MyString&& s = MyString("abc");
	// MyString&& s1 = s;	// error.
	MyString& ls = s;	// 이거 됨.
	
	const int a = 10;
	// a = 2; // error. lvaue인데 왼쪽에 올 수 없다.

	// rvalue인데 왼쪽에 올 수 있다. 이건 왜 가능?
	std::string("a") + std::string("b") = std::string("c");


}