#include <iostream>

using std::cout;
using std::endl;

template<typename T, typename S>
void add(T t, S s) {
	T ret = t + s;
	cout << ret << endl;
}

template<typename T, typename S>
void add2(T t, S s) {
	auto ret = t + s;		// ���Ⱑ �ٽ�~
	cout << ret << endl;
}

template<typename T, typename S>
auto add3(T t, S s) {	// C++14���� decltype ���� trailing ���� ��� ����
	return t + s;
}

template<typename T, typename S>
auto add4(T t, S s) -> decltype(t + s) {	// return Ÿ���� �����ϴ� ����.
	//	decltype(t + s) ret = t + s; // �̷��Ե� ��� ����
	return t + s;
}

template<typename T, typename S>
auto add5(T t, S s) -> decltype(t + s) {	// �� ��� decltype�� ������ ������ ����. �ݵ�� �ʿ�.
	if (t < s) return t;
	return s;
}

//template<typename T, typename S>
//auto add6(T t, S s) {	// ������ ����
//	if (t < s) return t;
//	return s;
//}

int main() {
	add(1, 1.2);	// 2
	add(1.2, 1);	// 2.2

	add2(1, 1.2);	// 2.2
	add2(1.2, 1);	// 2.2

	cout << add3(1, 1.2) << endl;

	// add6(1, 1.2); // ������ ���� �߻�. decltype�� ���.
}