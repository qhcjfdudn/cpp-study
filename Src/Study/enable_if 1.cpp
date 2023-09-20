#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T, typename S = std::enable_if_t<std::is_integral_v<T>>>
void foo() {
	cout << "is_integral_v" << endl;
}

template<typename T, typename S = typename std::enable_if<std::is_floating_point_v<T>>::type>
void foo() {
	cout << "is_floating_point_v" << endl;
}

int main() {
//	foo<int>();		// error 1. 인수 목록이 일치하는 함수 템플릿의 인스턴스가 없습니다.
//	foo<float>();

	// error 2.
	// 컴파일도 되지 않는다. 극단적으로 보면 다음과 같다.
	//	template<typename T, typename S = int>
	//	template<typename T, typename S = float>
	// 둘은 모양이 같다. 모호한 상황 발생. 그래서 enable_if는 이런 상황이 만들어질 수 있기 때문에
	// 이러한 모양을 권장하지 않는다.
}