#pragma once
#include <iostream>

const char* wrap(const char* str);

class MyString {
	char* _str;
public:
	explicit MyString(const char* str);
//	MyString(const char* str);

	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;
	~MyString();
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};