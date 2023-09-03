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
}