#include <iostream>

using std::cout;
using std::endl;

struct St {
	int a, b;
};

class C {
	int a, b;
	float c;
public:
	C(std::initializer_list<int> it) {
		a = *(it.begin() + 0);
		b = *(it.begin() + 1);
	}
	int getA() const { return a; }
	int getB() const { return b; }
};

int main() {
	auto f = [](int x) {
		return x;
	};

	// int nums[f(10)]; // C++17에서 가능.
	// lambda의 형태를 보고 암묵적으로
	// constexpr이 붙는다.

	St st1{ 1, 2 };
	St st2{ 1 };

	cout << st2.a << " " << st2.b << endl;

	C c1{ 1, 2 };
	C c2{ 1 };

	cout << c2.getA() << " " << c2.getB() << endl;
}