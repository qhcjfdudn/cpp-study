#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0 >
void foo() {							// ���� ���� Ÿ���̶�� �ĺ��ڸ� ������� �ʾƵ� ��.
	cout << "is_integral_v" << endl;	// 0�� �Ҵ���, enable_if�� �������� Substitution Failure�� �����ϴ� idiom
										// idiom �κ��� �ٸ� ���·� ������ �����ϴ�.
}

template<typename T, typename std::enable_if<std::is_floating_point_v<T>, int>::type = 0>
void foo() {
	cout << "is_floating_point_v" << endl;
}

int main() {
	foo<int>();		// is_integral_v
	foo<float>();	// is_floating_point_v
	foo<double>();	// is_floating_point_v
}