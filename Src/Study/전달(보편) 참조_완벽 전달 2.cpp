#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T>
void foo(T&& v) {	// ��, lvalue, rvalue reference 3������ �� ���� �� �ִ�.
	cout.setf(std::ios_base::boolalpha);
	cout << "lvalue ref T: " << std::is_lvalue_reference_v<T> << endl;
	cout << "rvalue ref T: " << std::is_rvalue_reference_v<T> << endl;
	cout << "lvalue ref T&: " << std::is_lvalue_reference_v<T&> << endl;
	cout << "rvalue ref T&: " << std::is_rvalue_reference_v<T&> << endl;
	cout << "lvalue ref T&&: " << std::is_lvalue_reference_v<T&&> << endl;
	cout << "rvalue ref T&&: " << std::is_rvalue_reference_v<T&&> << endl;
	cout.unsetf(std::ios_base::boolalpha);

	// T�� ���� int�ε�, T&&�� ���� �򰡰� T&�� �Ǿ���. int ������ �Ҵ��ص�.
	// ���� �Ʒ��� ����. -> template/auto�� &&�� �����, �������ϸ� ������ �ȴ�.
	v = 5;
}

template<typename T>
void goo(T& v) {
	cout << "lvalue ref T: " << std::is_lvalue_reference_v<T> << endl; // 0
	// �׷��� �Ķ���͸� T&&�� ���� ����, �����ڸ� �����ϸ� 1
	
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)> << endl;
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)&> << endl;
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)&&> << endl;
}

// ��Ģ
// ���ø����� ���� T, �ڵ忡�� ���� ref -> �� ref ���
// && -> &&
// & & -> &
// & && -> &
// && & -> &
// && && -> &&
//

// �ᱹ �������� ��� T&, T&& �������� ������� ���̴�. T�δ� ��������� �ʴ´�?
// �׽�Ʈ�غ� ����� �׷��� �ǹ��Ѵ�. ��� ����� reference�� ���´�.
// template�� type T��.. T ��ü�� ���� ���۷����� ���� �� ����. decltype���� ����
// ����� ���۷����� ����.
// �׷��� template/auto�� �Բ� ���� reference�� �޵��� ���������.
// �׸��� ������� T�� ���� reference�� ��� �ȴ�. �ű��ϴ�.
//

int main() {
	int num = 1;
	int& num1 = num;

	foo(num);
	cout << endl;
	foo(num1);
	cout << endl;
	foo(3);			// lvalue ref T / rvalue ref T ��� false ���. �� �� �� ��..
	cout << endl;

	goo(num1);
}