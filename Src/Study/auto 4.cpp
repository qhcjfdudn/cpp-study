#include <iostream>

using std::cout;
using std::endl;

template<int N0, int N1>
int add() {
	return N0 + N1;
}

// C++17���� �Ʒ� ����.
template<auto N0, auto N1>
auto add2() {
	return N0 + N1;
}

template<auto... Args>
auto sum(int a) {
	return (Args + ...);	// Fold Expression
}

// Fold Expression
// Args + ...		: (A[0] + (A[1] + (A[2] + ... A[N - 1])))
// ... + Args		: (((A[0] + A[1]) + A[2]) + ... A[N - 1])
// Args + ... + B	: (A[0] + (A[1] + (A[2] + ... (A[N - 1] + B)))
// B + ... + Args	: (((B + A[0]) + A[1]) + A[2]) + ... A[N - 1])
//
// �ٸ� ������ + ���(op)�� ���δ�. 
//

int main() {
	cout << add<1, 2>() << endl;	// 3
	cout << add<1, 20000000000>() << endl;	// ���� ������.
	cout << add2<1, 20000000000>() << endl;	// 20000000001

	cout << sum<1, 2, 200000000000, 4>(12) << endl;
}