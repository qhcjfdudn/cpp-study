#include <iostream>
using namespace std;

class Person {
	int _age;
	float _weight;
public:
	Person() : _age(0), _weight(0.0) {
		cout << "default ������" << endl;
	}
	Person(int age, float weight) : _age(age), _weight(weight) {
		cout << "������" << endl;
	}
	Person(const Person& p)
		: _age(p._age), _weight(p._weight) {
		cout << "���� ������" << endl;
	}
	Person& operator=(const Person& p) {
		cout << "���� ���� ������" << endl;
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
	Person p1{ 1, 2.0 };	// "������"
	Person p2;				// "����Ʈ ������"
	p2 = p1;				// "���� ���� ������"
	Person& p3 = p2;		// ���������� �����͸� ����
	Person p4(p3);			// "���� ������"

	// �� ����
	func1(p1);					// "���� ������"
	// �Ʒ��� C++ �����Ϸ��� ����ȭ ��Ų ���·�
	// �����ڰ� ȣ��ǰ� ���� �����ڴ� ȣ����� �ʴ´�.
	func1({ 2, 3.0 });			// "������"
	func1(Person(2, 3.0));		// "������"
	func1(Person{ 2, 3.0 });	// "������"

	// ������
	func2(p1);					// ���������� �����͸� ����
//	func2({ 2, 3.0 });			// error.
//	func2(Person(2, 3.0));		// error.

	func3(p1);				// ���������� �����͸� ����
	func3({ 1, 2.0 });		//	"������"
	func3(Person(1, 2.0));	// "������"
	func3(Person());		//	"����Ʈ ������"

	func4({ 0, 2.0 });		// "������" - "���� ������"
							// : return���� ����.
	Person p5 = func4(p1);	// "���� ������" - "���� ������"
							// : ��������� 2�� ȣ��Ǵ� �־��� ���.
	
	Person p6 = func5({ 0, 2.0 });		// "������" - "���� ������" - return���� ����.
	Person p7 = func5(p1);				// "���� ������" - return���� ����.
}