#include <iostream>
#include <string>

int main() {
	std::cout << &"123" << std::endl;	// 아래와 같다. 상수 메모리에 있는 문자열
	std::cout << &"123" << std::endl;	// 00007FF6523B0480

	std::string s = "123";
	const char* sp = s.c_str();
	printf("sp: %p\n", sp);		// 00000041D23FF570
	// 주소값이 상수 메모리의 값과 다르다.
	// 문자열 복사가 일어났음을 알 수 있다.
}