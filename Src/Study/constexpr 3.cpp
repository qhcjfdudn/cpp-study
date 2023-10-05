#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template <typename T>
auto getValue(T t) {
	if constexpr (std::is_pointer<T>())
	// if constexpr (std::is_pointer_v<T>)
		return *t;
	else return t;
}

template <typename T>
auto getValue2(T t) {
	if constexpr (std::is_pointer_v<T>)
	// if (std::is_pointer_v<T>)	// ������ error.
	//	getValue2�� ���޵Ǵ� Ÿ���� int ���� �� �� ���
	// *t ó�� ���۷��� �ؼ� ���� ������ �� ���
	// ������ ������ �߻��Ѵ�.
	// �׷��� if constexpr�� ��쿡�� ������ ��
	// ������ if ���ǿ� ���� ���۷��� �ڵ尡 ������Ƿ�
	// ���������� �������� �ȴ�.
		cout << *t << endl;
	else
		cout << t << endl;
}

int main() {
	int num = 3;
	int* pNum = &num;

	cout << getValue(num) << endl;
	cout << getValue(pNum) << endl;

	getValue2(num);
	getValue2(pNum);
}