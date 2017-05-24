#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <list>
#include <chrono>

/************************************************************
*					Data Race Bad!!!						*
*************************************************************/

//struct List {
//	struct Node {
//		int _x;
//		Node* _next;
//
//		Node(int y) : _x(y), _next(nullptr) {}
//	};
//
//	// List
//	Node* _head;
//	List() : _head(nullptr) {}
//
//	void insert(int x) {
//		auto node = new Node(x);
//		node->_next = _head;
//		_head = node;
//	}
//	 
//	int count() const;
//};
//
//void thFun(List& list) {
//	for (int i = 0; i < 100; ++i) {
//		list.insert(i);
//	}
//}
//
//int main() {
//	List list;
//	std::vector<std::thread> workers;
//	for (int i = 0; i < 10; ++i) {
//		workers.push_back(std::thread(&thFun, std::ref(list)));
//	}
//	for (std::thread& th : workers) th.join();
//	int total = list.count();
//
//	std::cout << total << std::endl;
//
//	system("PAUSE");
//	return 0;
//}
//
//int List::count() const {
//	int n = 0;
//
//	auto cur = _head;
//	while (cur != nullptr) {
//		++n;
//		cur = cur->_next;
//	}
//	return n;
//}

/*******************************************************************
*				Data Race Safe!
********************************************************************/

void toSin(std::list<double>&& list) {
	std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleeps thread for 1s
	std::for_each(list.begin(), list.end(), [](double& x) {
		x = sin(x);
	});
	std::for_each(list.begin(), list.end(), [](double& x) {
		int count = static_cast<int>(10 * x + 10.5);
		for (int i = 0; i < count; ++i)
			std::cout.put('*');
		std::cout << std::endl;
	});
}

int main() {
	std::list<double> list;
	// access list from main thread
	const double pi = 3.141592;
	const double epsilon = 0.0000001;

	for (double x = 0.0; x < 2 * pi + epsilon; x += pi / 16)
		list.push_back(x);

	// start thread
	// Since we use move instead of ref, we give control to the new thread
	std::thread th(&toSin, std::move(list));
	
	// join thread
	th.join();

	system("pause");
	return 0;
}