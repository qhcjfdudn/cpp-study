#include <iostream>
using namespace std;

class Person {
	int _age;
	float _weight;
public:
	Person() : _age(0), _weight(0.0) {
		cout << "default 생성자" << endl;
	}
	Person(int age, float weight) : _age(age), _weight(weight) {
		cout << "생성자" << endl;
	}
	Person(const Person& p)
		: _age(p._age), _weight(p._weight) {
		cout << "복사 생성자" << endl;
	}
	Person& operator=(const Person& p) {
		cout << "복사 대입 연산자" << endl;
		_age = p._age;
		_weight = p._weight;
		return *this;
	}
};

void func1(Person p) {}
void func2(Person& p) {}
void func3(const Person& p) {}
Person func4(Person p) { return p; }
Person func5(const Person& p) { return p; }

int main() {
	Person p1{ 1, 2.0 };	// "생성자"
	Person p2;				// "디폴트 생성자"
	p2 = p1;				// "복사 대입 연산자"
	Person& p3 = p2;		// 내부적으로 포인터만 변경
	Person p4(p3);			// "복사 생성자"

	// 값 복사
	func1(p1);					// "복사 생성자"
	// 아래는 C++ 컴파일러가 최적화 시킨 형태로
	// 생성자가 호출되고 복사 생성자는 호출되지 않는다.
	func1({ 2, 3.0 });			// "생성자"
	func1(Person(2, 3.0));		// "생성자"
	func1(Person{ 2, 3.0 });	// "생성자"

	// 참조자
	func2(p1);					// 내부적으로 포인터만 변경
//	func2({ 2, 3.0 });			// error.
//	func2(Person(2, 3.0));		// error.

	func3(p1);				// 내부적으로 포인터만 변경
	func3({ 1, 2.0 });		//	"생성자"
	func3(Person(1, 2.0));	// "생성자"
	func3(Person());		//	"디폴트 생성자"

	func4({ 0, 2.0 });		// "생성자" - "복사 생성자"
							// : return에서 동작.
	Person p5 = func4(p1);	// "복사 생성자" - "복사 생성자"
							// : 복사생성자 2번 호출되는 최악의 경우.
	
	Person p6 = func5({ 0, 2.0 });		// "생성자" - "복사 생성자" - return에서 동작.
	Person p7 = func5(p1);				// "복사 생성자" - return에서 동작.
}