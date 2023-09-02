#pragma warning(disable: 4996)
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class String {
private:
	char* _chars;

public:
	String(String& s) : _chars(s._chars){
		cout << "생성자2" << endl;
	}
	String(const char* chars) 
		: _chars(new char[strlen(chars) + 1])
	{
		cout << "생성자" << endl;
		strcpy(_chars, chars);
	}

	String& operator=(const String& s) {
		cout << "대입연산자" << endl;
		return *this;
	}


	char& operator[](int index) { // 아래 기본 버전의 대안.
		const String& s = *this;
		const char& c = s[index];
		return const_cast<char&>(c);
	}
	
	//char& operator[](int index) {	// 아래와 구분짓기 위한
	//	return _chars[index];		// 그러나 많은 중복코드 발생
	//}

	const char& operator[](int index) const {
		return _chars[index];
	}
};

int main() {
	String s0("abc");

	const String& s1 = s0;
	s0[0] = 'd';
	// s1[2] = 'e';	// error. s1은 const이기 때문. 하지만
					// s1이 const여도
					// s0의 값을 바꾸는 것으로
					// 내부 값이 바뀔 수 있다.

	cout << s0[0] << endl;
	cout << s1[0] << endl;
}