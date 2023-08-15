#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i < 4; ++i) {
		static int j = 1;
		++j;
		cout << j << endl;
	}
	static int j = 1;
	cout << j << endl;
}