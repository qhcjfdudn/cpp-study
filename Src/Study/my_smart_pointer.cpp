#include <iostream>

template<typename T>
class Ptr {
	T* obj;
	int* cnt;
public:
	Ptr(T* p = nullptr) : obj(p), cnt(new int) {
		*cnt = 1;
	}
	Ptr(const Ptr& other) : obj(other.obj), cnt(other.cnt) {
		++(*cnt);
	}
	~Ptr() {
		if (--(*cnt) == 0)
		{
			delete obj;
			delete cnt;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main() {
	Ptr<int> pt{ new int(4) };
	std::cout << *pt << std::endl;
	
	*pt = 2;
	std::cout << *pt << std::endl;
	
	Ptr<int> pt2(pt);
	*pt2 = 3;
	std::cout << *pt << std::endl;
}