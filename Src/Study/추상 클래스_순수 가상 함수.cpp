#include <iostream>
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	virtual ~Shape() {
		cout << "Shape" << endl;
	}
//	virtual ~Shape() = 0;	// 다른 순수 가상 함수 없이(멤버 함수는 있을 수 있다.)
							// 소멸자만 순수 가상 함수로 만들어주면
							// 순수 가상 함수이지만 멤버 함수는 쓸 수 있도록
							// 만들 수 있다.
};

class Rectangle : public Shape {
	int _height;
	int _weight;
public:
	Rectangle(int height, int weight)
		: _height(height), _weight(weight) {}
	virtual ~Rectangle() override {
		cout << "Rectangle" << endl;
	}

	virtual double getArea() const override {
		return _height * _weight;
	}
};

int main() {
	Rectangle r1(3, 5);
	Shape& s1 = r1;

	cout << s1.getArea() << endl;
}