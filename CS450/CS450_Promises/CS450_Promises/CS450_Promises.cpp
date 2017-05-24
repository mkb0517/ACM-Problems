#include <thread>
#include <future>
#include <iostream>
#include <string>
#include <exception>
#include <chrono>

/****************************************************
 *					Pass by move					*
 ****************************************************/

//void thFun(std::promise<std::string>&& prms) {
//	std::string str("Hello from future!");
//	prms.set_value(str);
//}
//
//int main() {
//	std::promise<std::string> prms;
//	std::future<std::string> ftr = prms.get_future();
//	std::thread th(&thFun, std::move(prms));
//	std::cout << "Hello from main!" << std::endl;
//	std::string str = ftr.get();
//	std::cout << str << std::endl;
//	th.join();
//
//	system("pause");
//	return 0;
//}

/****************************************************
*					Pass by Reference				*
*****************************************************/

//void thFun(std::promise<std::string>& prms) {
//	std::string str("Hello from future!");
//	std::cout << "String Data: " << (void*)str.data() << std::endl;
//	prms.set_value(str);
//}
//
//int main() {
//	std::promise<std::string> prms;
//	std::thread th(&thFun, std::ref(prms));
//	std::cout << "Hello from main!" << std::endl;
//	std::future<std::string> ftr = prms.get_future();
//	std::string str = ftr.get();
//	std::cout << str << std::endl;
//	std::cout << "String Data: " << (void*)str.data() << std::endl;
//	th.join();
//
//	system("pause");
//	return 0;
//}

/****************************************************
 *					Exception!						*
 ****************************************************/

//void thFun(std::promise<std::string>&& prms) {
//	try {
//		std::string str("Hello from future!");
//		throw(std::exception("Exception from future!"));
//		prms.set_value(str);
//	}
//	catch (...) {
//		prms.set_exception(std::current_exception());
//	}
//}
//
//int main() {
//	std::promise<std::string> prms;
//	std::future<std::string> ftr = prms.get_future();
//	std::thread th(&thFun, std::move(prms));
//	std::cout << "Hello from main!" << std::endl;
//	try {
//		std::string str = ftr.get();
//		std::cout << str << std::endl;
//	}
//	catch (std::exception& e){
//		std::cout << e.what() << std::endl;
//	}
//	th.join();
//
//	system("pause");
//	return 0;
//}

/****************************************************
 *					Async!!!!!!!					*
 ****************************************************/

//std::string fun() {
//	std::string str("Hello from future!");
//	throw(std::exception("Exception from task!"));
//	return str;
//}
//
//int main() {
//	auto ftr = std::async(&fun);
//	std::cout << "Hello from main!" << std::endl;
//	try {
//		std::string str = ftr.get();
//		std::cout << str << std::endl;
//	}
//	catch (std::exception e) {
//		std::cout << e.what() << std::endl;
//	}
//
//	system("pause");
//	return 0;
//}

/****************************************************
 *				  Waiting for End					*
 ****************************************************/

void fun() {
	std::cout << "Starting Task." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(8));
	std::cout << "Ending task." << std::endl;
}

int main() {
	auto ftr = std::async(&fun);
	std::cout << "Exiting from main!" << std::endl;

	system("pause");
	return 0;
}