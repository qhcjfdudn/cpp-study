#include <iostream>
#include <cfloat>

using std::cout;
using std::endl;

union ID
{
	char chars[10];
	int integer;
};

int main() {
	// ���� ��Ʈ�迭 �״�� Ÿ���� �ٲٴ� ���
	int i = 1;
	float f = i;
	float* fp = reinterpret_cast<float*>(&i);
	cout << *fp << endl;
	cout << FLT_TRUE_MIN << endl;
	cout << f << endl;

	
	// Union�� ���� ����
	ID id;
	id.integer = 10;
	int* p = reinterpret_cast<int*>(&id);
	cout << p << endl;	// 10


	// ����̽��� ����� �޸� �ּ�(�ϵ��ڵ�)���� ����
	//	Device* device = reinterpret_cast<Device*>(0x612e);

	// static_cast�� reinterpret_cast�� ����
	int staticInt = 7;
	float staticFloat = static_cast<float>(staticInt);

	cout << staticInt << endl;		// 7
	cout << staticFloat << endl;	// 7

	int reinterpretInt = 7;
	// float* reinterpretFloat = &rnum;	// ������ ����.
										// "int *" ������ ���� ����Ͽ� 
										// "float *" ������ ����Ƽ�� 
										// �ʱ�ȭ�� �� �����ϴ�.

	float* reinterpretFloat = reinterpret_cast<float*>(&reinterpretInt);	// ����.

	cout << &reinterpretInt << endl;	// 0000008EB24FF674
	cout << reinterpretFloat << endl;	// 0000008EB24FF674

	cout << reinterpretInt << endl;		// 7
	cout << *reinterpretFloat << endl;	// 9.80909e-45
}