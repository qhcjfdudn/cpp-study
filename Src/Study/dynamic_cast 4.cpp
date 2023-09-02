#include <iostream>

class Parent {};

class Child : public Parent {};

int main() {
	Parent* p = new Child();
//	Child* c = dynamic_cast<Child*>(p); Parent가 다형 클래스가 아니라서 컴파일 에러
	Child* c = static_cast<Child*>(p);	// 상속 관계에서 up/down 무관하게 쓸 수 있다.
										// 다만 down casting이어서 실제 객체가 Parent 타입이라면
										// 사용이 위험해진다.
										// static_cast의 down casting 사용은 안전하지 않다.
}