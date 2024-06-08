#include <iostream>

template<typename T>
class Ptr {
	T* obj;
	int* ref;
public:
	Ptr(T* p = nullptr) : obj(p), ref(new int) {
		*ref = 1;
	}
	Ptr(const Ptr& other) : obj(other.obj), ref(other.ref) {
		++(*ref);
	}
	~Ptr() {
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
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