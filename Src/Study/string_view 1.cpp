#include <iostream>
#include <string>

int main() {
	std::cout << &"123" << std::endl;	// �Ʒ��� ����. ��� �޸𸮿� �ִ� ���ڿ�
	std::cout << &"123" << std::endl;	// 00007FF6523B0480

	std::string s = "123";
	const char* sp = s.c_str();
	printf("sp: %p\n", sp);		// 00000041D23FF570
	// �ּҰ��� ��� �޸��� ���� �ٸ���.
	// ���ڿ� ���簡 �Ͼ���� �� �� �ִ�.
}