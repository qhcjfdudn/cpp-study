#pragma once
class Person2
{
	static int si;
//	static int si = 3;			// in-class initializer�� �ִ� ����� const���� �մϴ�.
//	static const int si = 3;	// ����
//	inline static int si = 3;	// C++17���� ����.

public:
	Person2();
	static void print();		// static ������� ���� ����.
};

