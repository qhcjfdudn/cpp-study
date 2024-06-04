#include <iostream>
#include <future>

int main() {
	std::promise<int> pi;
	std::future<int> fi = pi.get_future();

	pi.set_value(4);
	// pi.set_value(4);		// 2�� set�ϸ� error
	std::cout << fi.get() << std::endl;
	// std::cout << fi.get() << std::endl;	// 2�� get�ϸ� error

	// �ݵ�� set 1��, get 1���̾�� �Ѵ�.
	//�׸��� ���� set�� ���� get�� �Ѵٸ�, block�� ä�� set�� ��ٸ���.
}