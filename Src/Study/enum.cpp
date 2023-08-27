#include <iostream>
using namespace std;

enum TextAttrs {
	Bold = 1,
	Italic = 2,
	Underline = 4,
	Strikethrough = 8
};

enum class Colors {
	Red, Blue, Green, Alpha, SIZE
};

enum class Int64 : int64_t {	// 가장 기본은 4byte
	num = 100000000000
};

int main() {
	int total = 0, colors[4] = { 1, 2, 3, 5 };
	for (int i = 0; i < static_cast<int>(Colors::SIZE); ++i) {
		total += colors[i];
	}

	int textAttrs = 0;
	textAttrs |= TextAttrs::Bold;
	textAttrs |= TextAttrs::Underline;

	if (textAttrs & TextAttrs::Underline)
		cout << "Underline" << endl;

	cout << static_cast<int>(Int64::num) << endl;

	Colors r = Colors::Red;
	Colors g = (Colors)2;
	Colors b = static_cast<Colors>(1);

	if (r == Colors::Red) {
		cout << "Red" << endl;
	}
	if (g == Colors::Green) {
		cout << "Green" << endl;
	}
}