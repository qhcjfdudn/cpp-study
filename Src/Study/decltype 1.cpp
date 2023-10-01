#include <iostream>

using std::cout;
using std::endl;

int func(float) { return 10; }

int global_num = 10;
int& ref_func() {
	cout << "decltype()�� �������� �Լ� ��ü�� ������� �ʽ��ϴ�." << endl;
	return global_num;
}

class Person {
public:
	float _height;
	float _weight;
};

int main() {
	decltype(1) num = 10;

	decltype(num) num1 = 20;		// int
	decltype(num1)& num2 = num1;	// int&
	decltype(num2) num3 = num1;		// int& . ���۷����� �߷��� �� �ִ�.

	const decltype(num) num4 = num2;	// const int
	const decltype(num)& num5 = num2;	// const int&

	// �̸��� ��ȣ 2���� ���۷����� �ȴ�.
	// decltype((num)) num4 = 10;	// error. rvalue�� ������ �� ���.
	decltype((num)) num6 = num1;	// int&

	decltype(1 + 2.2f) num7 = 1.3f;	// float

	// �迭
	int nums[] = { 1, 2, 3 };

	// decltype�� �迭�� �����Ͱ� �ƴ� ���� �迭 Ÿ������ �޴´�!!
	// decltype(nums) nums1 = { 1, 2, 3, 4, 5};	// �̴ϼ� ������ ���� �ʹ� �����ϴ�.
	decltype(nums) nums2 = { 1, 2 }; // int nums2[3]
	decltype(nums) nums3{ 1, 2, 3 }; // int nums2[3]


	// �Լ��� ���� ���
	auto f = func;
	cout << f(1.1f) << endl;
	decltype(func) f1;	// �Լ� ����. ���Ǵ� ����. �׷��� ���� ��ŷ ���� �߻�.
	// cout << f1(1.1f) << endl;	// fatal error LNK1120: 1���� Ȯ���� �� ���� �ܺ� �����Դϴ�.

	decltype(func)& f2 = func;
	decltype(func)* f3 = func;

	cout << f2(1.1f) << endl;
	cout << f3(1.1f) << endl;

	decltype(func(1.1f)) num8 = 40;
	
	decltype(ref_func()) num9 = num8;

	Person p;
	decltype(p._weight) weight0; // float

	// ���� ��� �ȴ�. ������ ������� �ʴ´�.
	// float���� ����� �͸� ������ Ÿ�ӿ� Ȯ���ϱ� ����.
	// �׷��� �Ʒ��� ���� ��� ����
	decltype(Person::_weight) weight1; // float
}