#pragma once
class Person2
{
	static int si;
//	static int si = 3;			// in-class initializer가 있는 멤버는 const여야 합니다.
//	static const int si = 3;	// 가능
//	inline static int si = 3;	// C++17부터 가능.

public:
	Person2();
	static void print();		// static 멤버에만 접근 가능.
};

