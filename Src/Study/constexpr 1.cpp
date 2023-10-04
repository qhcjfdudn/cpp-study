#include <iostream>

using std::cout;
using std::endl;

constexpr int fibo(int n) {
	return n <= 1 ? n : fibo(n - 2) + fibo(n - 1);
}

template<int N>
void func() {
	cout << N << endl;
}
int main() {
	constexpr int value = fibo(50);

	// �Ʒ� �� �������� ������ ������ ���ٴ� ��,
	// ������ Ÿ�ӿ� value�� ������ ġȯ�� �ȴٴ� ����
	// ���� �޴´ٴ� �ǹ��̴�.
	int arr[value];
	func<value>();

	int num = 10;
	// constexpr int value2 = fibo(num); // error.
	// �Ŀ� ��� ���� �־�� �ϴµ�, ������ ���޵Ǹ�
	// ������ Ÿ�ӿ� ����� ���� ������ �� ����.

	// void f(constexpr int a) {}	// error. �Ű������� �����ڰ� �߸��Ǿ����ϴ�.

}