#include <iostream>
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	virtual ~Shape() {
		cout << "Shape" << endl;
	}
//	virtual ~Shape() = 0;	// �ٸ� ���� ���� �Լ� ����(��� �Լ��� ���� �� �ִ�.)
							// �Ҹ��ڸ� ���� ���� �Լ��� ������ָ�
							// ���� ���� �Լ������� ��� �Լ��� �� �� �ֵ���
							// ���� �� �ִ�.
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