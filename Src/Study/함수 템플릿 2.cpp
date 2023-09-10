#include <iostream>

using std::cout;
using std::endl;

template<typename T, int N>
T get_back(T (&arr)[N]) {
	return arr[N - 1];
}

int main() {
	int nums1[] = { 1, 2, 3 };
	int nums2[] = { 4, 5, 6, 7, 8 };
	double num3[] = { 1.2, 3.4 };
	cout << get_back(nums1) << endl;
	cout << get_back<int>(nums2) << endl;
	cout << get_back(num3) << endl;

	// �Ʒ��� ����, ���� ���� �ٸ� Ÿ������ �� �� �ִ�.
	cout << typeid(nums1).name() << endl;	// int [3]
	cout << typeid(nums2).name() << endl;	// int [5]
}