#include <iostream>

class Person {
	const std::string _name;
	float _weight;

public:
	Person(const std::string& n, float w) : _name(n), _weight(w) {}

	float getWeight(/* Person* this */) {
		return _weight;
	}
	
	float getWeight_const(/* const Person this */) const {
		return _weight;
	}
};

int main() {
	const Person p1("Hy", 50.2);				// ���� ������ ������ �ȵǴ� ��ü
//	std::cout << p1.getWeight() << std::endl;	// ��ü�� ��� �Լ� Person::getWeight��(��) ȣȯ���� �ʴ� ���� �����ڰ� �ֽ��ϴ�.
												// ��ü ����: const Person

//	Person* p2 = &p1;	// ������ �ȵǱ� ����.
						// �̰� �Ǹ�, p2->_weight�� p1�� ����� �����Ϸ���
						// �ڵ��� ����������. ����.

	std::cout << p1.getWeight_const() << std::endl;
}