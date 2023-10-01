#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

enum class Enumer {
	A, B, C
};

auto Func(Enumer en) {
	return static_cast<std::underlying_type_t<Enumer>>(en);
}

auto Func2(Enumer en) -> std::underlying_type_t<Enumer> {
	return static_cast<std::underlying_type_t<Enumer>>(en);
}

int main() {
	cout << Func(Enumer::A) << endl;
	cout << Func(Enumer::B) << endl;

	cout << Func2(Enumer::A) << endl;
	cout << Func2(Enumer::B) << endl;
}