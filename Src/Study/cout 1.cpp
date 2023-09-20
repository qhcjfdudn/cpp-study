#include <iostream>

using std::cout;
using std::endl;

class Person {
public:
	const std::string _name;
	Person(const std::string& name) : _name(name) {
		cout << "생성자!" << endl;
	}
	Person(const Person& p) : _name(p._name) {
		cout << "복사 생성자!" << endl;
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

	cout << Person("hack") << endl;	// hack 출력

	cout.put('a');
	cout.put('\n');
	cout.write("Hello!", 3) << endl;	// 주어진 문자열 중 3개만 출력
	
	cout.write("Hello!", 10) << 'a' << endl;	// 문자열보다 count가 크면 문자열 전체 출력

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

	// 3개 이상의 플래그가 있을 땐, 그걸 초기화해주는 2번째 인자 전달 필요.
	cout.setf(std::ios_base::left, std::ios_base::adjustfield);		// 왼쪽 정렬
	cout.setf(std::ios_base::right, std::ios_base::adjustfield);	// 오른쪽 정렬
	cout.setf(std::ios_base::internal, std::ios_base::adjustfield);	// 가운데 정렬

	cout.setf(std::ios_base::hex, std::ios_base::basefield);
	cout.setf(std::ios_base::oct, std::ios_base::basefield);
	cout.setf(std::ios_base::dec, std::ios_base::basefield);

//	std::hex(cout);	// 함수이다. 아래도 가능.
	cout << std::hex << 10 << endl;
}