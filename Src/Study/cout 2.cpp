#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setiosflags(ios_base::left)
		<< setbase(ios_base::adjustfield)
		<< setw(8)
		<< setfill('#')
		<< setprecision(1)	// ��ȿ������ ������ �ǹ�.
		<< showpos
		<< 142.32	// +1e+02##
		<< noshowpos	// unset �ʿ�
		<< endl;

	cout << 123 << endl;
}