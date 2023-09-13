#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T, typename S>
class Test {
public:
	T a;
	S b;
};

template<>
class Test<int, int> {
public:
	int c;
};

template<typename T>
class Test<float, T> {
public:
	T d;
};

// �Ʒ��� �����ϳ�, ���� ���� �Բ� ����Ǿ� ��ȣ�� ��Ȳ�� �����.
template<typename T>
class Test<T, T> {
public:
	T e;
};

int main() {
	Test<int, float> t1;
	t1.a; t1.b;
	Test<int, int> t2;
	t2.c;
	//Test<float, float> t3;	// ��ȣ�� ���.
	//t3.d;
	Test<float, int> t4;
	t4.d;
	Test<double, double> t5;
	t5.e;

	std::vector<int> vi;
	std::vector<bool> vb;
}