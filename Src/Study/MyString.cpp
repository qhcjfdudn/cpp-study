#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <utility>
#include "MyString.h"

using std::cout;
using std::endl;

const char* wrap(const char* str) {
	return str ? str : "";
}

MyString::MyString(const char* str)
	: _str(new char[strlen(str) + 1])
{
	strcpy(_str, str);
	cout << "Construct: " << _str << endl;
}

MyString::MyString(const MyString& other)
	: _str(new char[strlen(other._str) + 1])
{
	strcpy(_str, other._str);
	cout << "Copy Construct: " << _str << endl;
}
MyString::MyString(MyString&& other) noexcept
	: _str(other._str)
{
	other._str = nullptr;
	cout << "Move Construct: " << _str << endl;
}

MyString::~MyString() {
	cout << "Destruct: " << wrap(_str) << endl;
	delete[] _str;
}
MyString& MyString::operator=(const MyString& other) {
	delete[] _str;

	_str = new char[strlen(other._str) + 1];
	strcpy(_str, other._str);

	cout << "Copy operator: " << _str << " = " << other._str << endl;

	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
	cout << "Move operator: " << wrap(_str) << " = " << other._str << endl;

	delete[] _str;
	_str = std::move(other._str);
	other._str = nullptr;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return (os << str._str);
}
