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
		cout << "������2" << endl;
	}
	String(const char* chars) 
		: _chars(new char[strlen(chars) + 1])
	{
		cout << "������" << endl;
		strcpy(_chars, chars);
	}

	String& operator=(const String& s) {
		cout << "���Կ�����" << endl;
		return *this;
	}


	char& operator[](int index) { // �Ʒ� �⺻ ������ ���.
		const String& s = *this;
		const char& c = s[index];
		return const_cast<char&>(c);
	}
	
	//char& operator[](int index) {	// �Ʒ��� �������� ����
	//	return _chars[index];		// �׷��� ���� �ߺ��ڵ� �߻�
	//}

	const char& operator[](int index) const {
		return _chars[index];
	}
};

int main() {
	String s0("abc");

	const String& s1 = s0;
	s0[0] = 'd';
	// s1[2] = 'e';	// error. s1�� const�̱� ����. ������
					// s1�� const����
					// s0�� ���� �ٲٴ� ������
					// ���� ���� �ٲ� �� �ִ�.

	cout << s0[0] << endl;
	cout << s1[0] << endl;
}