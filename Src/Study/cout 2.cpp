#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setiosflags(ios_base::left)
		<< setbase(ios_base::adjustfield)
		<< setw(8)
		<< setfill('#')
		<< setprecision(1)	// 유효숫자의 개수를 의미.
		<< showpos
		<< 142.32	// +1e+02##
		<< noshowpos	// unset 필요
		<< endl;

	cout << 123 << endl;
}