#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

int main() {
	int num0 = 10;
	int& num1 = num0;
	// int& num1 = 10; // error.
	int&& num2 = 10;

	const int& num3 = 10;	// �̰͵� �Ǳ� ��.

	MyString&& s = MyString("abc");
	// MyString&& s1 = s;	// error.
	MyString& ls = s;	// �̰� ��.
	
	const int a = 10;
	// a = 2; // error. lvaue�ε� ���ʿ� �� �� ����.

	// rvalue�ε� ���ʿ� �� �� �ִ�. �̰� �� ����?
	std::string("a") + std::string("b") = std::string("c");


}