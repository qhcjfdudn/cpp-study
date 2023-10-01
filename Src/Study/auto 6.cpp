#include <iostream>

using std::cout;
using std::endl;

struct Person {
	float _weight;
	float _height;
};

int main() {
	Person p{ 60.1, 100.45 };
	auto [w, h] = p;

	cout << w << " " << h << endl;	// 60.1 100.45
}