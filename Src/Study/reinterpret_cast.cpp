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
	// 현재 비트배열 그대로 타입을 바꾸는 방법
	int i = 1;
	float f = i;
	float* fp = reinterpret_cast<float*>(&i);
	cout << *fp << endl;
	cout << FLT_TRUE_MIN << endl;
	cout << f << endl;

	
	// Union의 값에 접근
	ID id;
	id.integer = 10;
	int* p = reinterpret_cast<int*>(&id);
	cout << p << endl;	// 10


	// 디바이스가 연결된 메모리 주소(하드코딩)로의 접근
	//	Device* device = reinterpret_cast<Device*>(0x612e);

	// static_cast와 reinterpret_cast의 차이
	int staticInt = 7;
	float staticFloat = static_cast<float>(staticInt);

	cout << staticInt << endl;		// 7
	cout << staticFloat << endl;	// 7

	int reinterpretInt = 7;
	// float* reinterpretFloat = &rnum;	// 컴파일 에러.
										// "int *" 형식의 값을 사용하여 
										// "float *" 형식의 엔터티를 
										// 초기화할 수 없습니다.

	float* reinterpretFloat = reinterpret_cast<float*>(&reinterpretInt);	// 가능.

	cout << &reinterpretInt << endl;	// 0000008EB24FF674
	cout << reinterpretFloat << endl;	// 0000008EB24FF674

	cout << reinterpretInt << endl;		// 7
	cout << *reinterpretFloat << endl;	// 9.80909e-45
}