#include <iostream>
using namespace std;

class String {
	const char* s;
public:
	explicit String(const char* s) : s(s) {}
};

int main() {
//	String ss = "123";	// error. explicit�� ������ ����. �Ͻ���.
	String ss("123");	// �����. ����.

	String s1 = (String)"abc";	// C Style ����ȯ
	String s2 = String("abc");	// C++ Style ����ȯ
}