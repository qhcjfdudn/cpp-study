#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

// pointer�� ���� Ư��ȭ
template<typename T>
struct remove_pointer {
	using type = T;
};

template<typename T>
struct remove_pointer<T*> {
	using type = T;
};

template<typename T>
struct add_pointer {
	using type = T*;
};

template<typename T>
struct add_pointer<T&> {
	using type = T*;
};

int main() {
	int num = 2;
	std::add_pointer<int>::type pNum1 = &num;
	std::add_pointer_t<int> pNum2 = &num;	// ���� ����

	*pNum1 = 4;
	cout << num << endl;	// 4

	std::remove_pointer<int*>::type num2 = *pNum1;
	cout << num2 << endl;	// 4

	std::remove_pointer<int>::type num3 = *pNum1;	// �����Ͱ� ������ �Ϲ� Ÿ��.
	cout << num3 << endl;
	cout << typeid(num3).name() << endl;	// int
	
	std::remove_pointer<int**>::type num4;	// ���� �����ʹ� ������ Ÿ������.
	cout << typeid(num4).name() << endl;	// int * __ptr64
	
	remove_pointer<int*>::type num5 = *pNum1;
	cout << num5 << endl;

	std::remove_pointer<int&>::type num6 = num;	// �����ڵ� ���� ����
	cout << num6 << endl;
	cout << typeid(num6).name() << endl;
	
	add_pointer<int>::type pNum3 = &num;
	*pNum3 = 6;
	cout << num << endl;

	add_pointer<int**>::type pNum4;
	cout << typeid(pNum4).name() << endl;	// Ʈ���� ������~
	
	add_pointer<int&>::type pNum5;
	cout << typeid(pNum5).name() << endl;	// �����ڴ� ���ø� Ư��ȭ �ʿ�.
}