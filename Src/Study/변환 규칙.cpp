#include <iostream>
using namespace std;

int main() {
	char c{ 14213 };	// �߰�ȣ �ʱ�ȭ��
	int i = { 1.1f };	// Uniform Initialization�̶� �Ѵ�.
						// ���� ��� "��� ��ȯ"�� �ʿ��ϴٰ�
						// ������ error.

	int i2 = 1;
	const int i3 = 3;
	char c1{ i2 };	// ������ ����. ������ �ȵȴ�.
	char c2{ i3 };	// ok. ����� ��.
}