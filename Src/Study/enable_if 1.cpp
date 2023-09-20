#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T, typename S = std::enable_if_t<std::is_integral_v<T>>>
void foo() {
	cout << "is_integral_v" << endl;
}

template<typename T, typename S = typename std::enable_if<std::is_floating_point_v<T>>::type>
void foo() {
	cout << "is_floating_point_v" << endl;
}

int main() {
//	foo<int>();		// error 1. �μ� ����� ��ġ�ϴ� �Լ� ���ø��� �ν��Ͻ��� �����ϴ�.
//	foo<float>();

	// error 2.
	// �����ϵ� ���� �ʴ´�. �ش������� ���� ������ ����.
	//	template<typename T, typename S = int>
	//	template<typename T, typename S = float>
	// ���� ����� ����. ��ȣ�� ��Ȳ �߻�. �׷��� enable_if�� �̷� ��Ȳ�� ������� �� �ֱ� ������
	// �̷��� ����� �������� �ʴ´�.
}