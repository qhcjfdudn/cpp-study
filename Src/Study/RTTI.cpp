#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
	virtual ~Parent() {}
};

class Child : public Parent {};

int main() {
	Parent pp;
	Parent* p = new Child();
	cout << typeid(*p).name() << endl;	// 가상 함수가 없다면 정적으로 'Class Parent' 출력
										// 가상 함수라면 동적으로 'Class Child' 출력

	Child* c = dynamic_cast<Child*>(p);
	if (c == nullptr) {
		cout << "c의 가상 테이블이 변조되었다!" << endl;
	}
}