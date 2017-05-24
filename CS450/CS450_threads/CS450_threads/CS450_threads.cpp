#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void thFun(int& i) {
	std::cout << "Hi from worker " << i << "!\n";
}

void test(std::vector<std::thread> &workers) {
	for (int i = 0; i < 10; ++i) {
		auto th = std::thread(&thFun, std::ref(i));
		workers.push_back(std::move(th));
		assert(!th.joinable());
	}
}

int main() {
	std::vector<std::thread> workers;
	test(workers);
	std::cout << "Hi from main\n";

	for (std::thread& th : workers) {
		assert(th.joinable());
		th.join();
	}

	system("pause");
	return 0;
}