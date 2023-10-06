#include "MyString.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main() {
	std::vector<MyString> s{ MyString("abc") };

	cout << "reserve" << endl;
	s.reserve(10);
}