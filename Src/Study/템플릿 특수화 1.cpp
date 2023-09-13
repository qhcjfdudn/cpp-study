#include <iostream>	

using std::cout;
using std::endl;

class Test {};

template<typename T>
void swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<>
void swap<Test>(Test& a, Test& b) {
// void swap(Test& a, Test& b) {	// 이렇게도 사용 가능.
	cout << "swap" << endl;
}