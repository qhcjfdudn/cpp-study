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
	const Person p1("Hy", 50.2);				// 값의 변경이 있으면 안되는 객체
//	std::cout << p1.getWeight() << std::endl;	// 개체에 멤버 함수 Person::getWeight과(와) 호환되지 않는 형식 한정자가 있습니다.
												// 개체 형식: const Person

//	Person* p2 = &p1;	// 다음이 안되기 때문.
						// 이게 되면, p2->_weight로 p1의 멤버를 조작하려는
						// 코딩이 가능해진다. 오류.

	std::cout << p1.getWeight_const() << std::endl;
}