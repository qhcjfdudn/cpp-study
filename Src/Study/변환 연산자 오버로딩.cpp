#include <iostream>
using namespace std;

class String {
	const char* s;
public:
	explicit String(const char* s) : s(s) {}
};

int main() {
//	String ss = "123";	// error. explicit이 없으면 가능. 암시적.
	String ss("123");	// 명시적. 가능.

	String s1 = (String)"abc";	// C Style 형변환
	String s2 = String("abc");	// C++ Style 형변환
}