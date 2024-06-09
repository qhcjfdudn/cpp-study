#include <iostream>

// 함수가 인자로 전달받은 문자열을 읽기만 한다면
// 다음중 최선의 코드는 ?
void f1(std::string name) {}		// worst
// => name 뿐 아니라, 문자열 자체까지 복사
void f2(const std::string& name) {}	// good, not best
// 
void f3(std::string_view name) {}	// best

int main()
{
	std::string s = "to be or not to be";

	// 이렇게 쓰면 메모리, 속도 성능에서 크게 차이가 없다.
	f2(s);
	f3(s);

	// 이렇게 쓰면?
	f2("to be or not to be");	// 함수에서 사용하는 임시객체를 만든다.
	// 객체가 생성되는 굉장한 오버헤드들이 발생.
	f3("to be or not to be");	// 상수 메모리를 그대로 가리킨다.