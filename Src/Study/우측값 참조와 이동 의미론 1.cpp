#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <utility>

using std::cout;
using std::endl;

const char* wrap(const char* str) {
	return str ? str : "";
}

class String {
	char* _str;
public:
	explicit String(const char* str)
		: _str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
		cout << "Construct: " << _str << endl;
	}

	String(const String& other)
		: _str(new char[strlen(other._str) + 1])
	{
		strcpy(_str, other._str);
		cout << "Copy Construct: " << _str << endl;
	}
	String(String&& other) noexcept
		: _str(other._str)
	{
		other._str = nullptr;
		cout << "Move Construct: " << _str << endl;
	}

	~String() {
		cout << "Destruct: " << wrap(_str) << endl;
		delete[] _str;
	}
	String& operator=(const String& other) {
		delete[] _str;
		
		_str = new char[strlen(other._str) + 1];
		strcpy(_str, other._str);

		cout << "Copy operator: " << _str << " = " << other._str << endl;

		return *this;
	}

	String& operator=(String&& other) noexcept {
		cout << "Move operator: " << wrap(_str) << " = " << other._str << endl;
		
		delete[] _str;
		_str = std::move(other._str);
		other._str = nullptr;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& str)
	{
		return (os << str._str);
	}
};

template<typename T>
void swap(T& a, T& b) {
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main() {
	String s0{ "abc" };
 	s0 = String{ "def" };

	String s1("ABC");
	swap(s0, s1);
	cout << "s0: " << s0 << endl;
	cout << "s1: " << s1 << endl;
}