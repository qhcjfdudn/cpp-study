#include <iostream>
using namespace std;

class A {
public:
	int num;
};

class B : public A {
};

A operator+(const A& x, const A& y) {
	A ret;
	ret.num = x.num + y.num;
	return ret;
}

B operator+(const B& x, const B& y) {
	B ret;
	ret.num = x.num * y.num;
	return ret;
}

int main() {
	A a0{ 20 }, a1{ 30 };
	
	B b0, b1;
	b0.num = 20, b1.num = 30;

	A a2 = a0 + a1;
	cout << a2.num << endl;	// 50

	A a3 = b0 + b1;
	cout << a3.num << endl;	// 600

	A& a4 = b0;
	A& a5 = b1;

	A a6 = a4 + a5;
	cout << a6.num << endl;	// 50	// 오버로딩은 정적 결합.
}