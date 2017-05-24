#include <future>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

/********************************************************
 *				Async task assignemnt					*
 ********************************************************/

//int main() {
//	std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
//
//	std::vector<std::future<void>> futures;
//	for (int i = 0; i < 10; ++i) {
//		auto fut = std::async([] {
//			std::this_thread::sleep_for(std::chrono::seconds(2));
//			std::cout << std::this_thread::get_id() << " ";
//		});
//		futures.push_back(std::move(fut));
//	}
//
//	for (auto& item : futures) {
//		[](std::future<void>& fut) {
//			fut.wait();
//		};
//	}
//
//	std::cout << std::endl;
//	std::this_thread::sleep_for(std::chrono::seconds(10));
//
//	system("pause");
//	return 0;
//}

/********************************************************
 *			  Filesystem using experimental				*
 ********************************************************/

//#include <experimental/filesystem>
//#include <filesystem>
//
//typedef std::vector<std::string> string_vector;
//
//string_vector listDirectory(std::string && dir) {
//	string_vector listing;
//	std::string dirStr("\n> ");
//	dirStr += dir;
//	dirStr += ":\n";
//	listing.push_back(dirStr);
//
//	std::vector<std::future<string_vector>> futures;
//	for (std::experimental::filesystem::v1::directory_iterator it(dir); it != std::experimental::filesystem::v1::directory_iterator(); ++it) {
//		if (it->status) {
//			auto ftr = std::async(std::launch::async, &listDirectory, it->path().filename());
//			futures.push_back(std::move(ftr));
//		}
//		else {
//			listing.push_back(it->path().leaf());
//		}
//	}
//	for (auto& item : futures) {
//		[&listing](std::future<string_vector>& ftr) {
//			string_vector lst = ftr.get();
//			std::copy(lst.begin(),lst.end(), std::back_inserter(listing));
//			ftr.wait();
//		};
//	}
//}
//
//int main() {
//	std::string root = "C:\\Projects";
//	auto ftr = std::async(std::launch::async, &listDirectory, root);
//	try {
//		string_vector listing = ftr.get();
//		for (auto& item : listing) {
//			[](std::string& s) {
//				std::cout << s << " ";
//			};
//		}
//	}
//	catch (std::exception e) {
//		std::cout << e.what() << std::endl;
//	}
//	catch (...) {
//		std::cout << "Unknown exception..." << std::endl;
//	}
//	std::cout << "Press enter\n";
//	char c;
//	std::cin.get(c);
//	return 0;
//}