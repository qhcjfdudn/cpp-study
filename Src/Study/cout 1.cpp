#include <iostream>

using std::cout;
using std::endl;

class Person {
public:
	const std::string _name;
	Person(const std::string& name) : _name(name) {
		cout << "������!" << endl;
	}
	Person(const Person& p) : _name(p._name) {
		cout << "���� ������!" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p._name;
	return os;
}

int main() {
	cout << 'a' << endl;
	operator<<(cout, 'a') << endl;
	cout.operator<<(static_cast<char>('a')) << endl;

	cout << Person("hack") << endl;	// hack ���

	cout.put('a');
	cout.put('\n');
	cout.write("Hello!", 3) << endl;	// �־��� ���ڿ� �� 3���� ���
	
	cout.write("Hello!", 10) << 'a' << endl;	// ���ڿ����� count�� ũ�� ���ڿ� ��ü ���

	cout.width(10); cout.fill('?');
	cout << 'a' << endl;			// ?????????a

	cout.width(10); cout.fill('#');
	cout << "avc d" << endl;		// #####avc d

	cout.width(10); cout.fill('#');
	cout << "abcdefghijkl" << endl;	// abcdefghijkl

	cout.width(10); cout.fill(' ');
	cout << "avc d" << endl;		// "     avc d"

	cout.precision(10); cout << 0.123456789 << endl;

	cout.setf(std::ios_base::showpos); // formatting plag
	cout << 1 << endl;	// +1
	cout << 5 << endl;	// +5
	cout.unsetf(std::ios_base::showpos);

	cout << std::boolalpha;
	cout << true << endl;	// true
	cout << false << endl;	// false
	cout.unsetf(std::ios_base::boolalpha);
	cout << false << endl;	// 0

	// 3�� �̻��� �÷��װ� ���� ��, �װ� �ʱ�ȭ���ִ� 2��° ���� ���� �ʿ�.
	cout.setf(std::ios_base::left, std::ios_base::adjustfield);		// ���� ����
	cout.setf(std::ios_base::right, std::ios_base::adjustfield);	// ������ ����
	cout.setf(std::ios_base::internal, std::ios_base::adjustfield);	// ��� ����

	cout.setf(std::ios_base::hex, std::ios_base::basefield);
	cout.setf(std::ios_base::oct, std::ios_base::basefield);
	cout.setf(std::ios_base::dec, std::ios_base::basefield);

//	std::hex(cout);	// �Լ��̴�. �Ʒ��� ����.
	cout << std::hex << 10 << endl;
}