#include <future>
#include <vector>
#include <iostream>
#include <string>
// This is the experiemental filesystem implemented in the code, with a few changes
#include <experimental/filesystem>
#include <filesystem>


/********************************************************
 *			  Filesystem using experimental				*
 ********************************************************/

struct Result {
	std::vector<std::string> files;
	std::vector<std::experimental::filesystem::path> dirs;

	Result() {}
	// Overloaded Copy Constuctor which we need for copying the results in main
	Result(Result&& r) : dirs(std::move(r.dirs)), files(std::move(r.files)) {}
	// the assignement operator cannot be deleted for the program to compile, which overloading the copy or move constructor implicitly does
	Result& operator=(const Result&) = default;
};

Result listDir(std::experimental::filesystem::path&& dir) {
	Result result;
	// Here we need to find where the directory_iterator definition is stored. It happens to be in experimental/directory so we must include that
	// Loop through the directory path that's been passed to the function
	for (std::experimental::filesystem::directory_iterator it(dir); it != std::experimental::filesystem::directory_iterator(); ++it) {
		// is_directory() has been moved from path and is now located in filesystem. It takes a path as an argument
		// If the next item in the path is a subdirectory, push it back onto the stack
		if (std::experimental::filesystem::is_directory(it->path())) {
			result.dirs.push_back(it->path());
		}
		else {
			// leaf() has been deprecated and replaced with filename(). It is no longer returns a string, so we must convert it with string()
			result.files.push_back(it->path().filename().string());
		}
	}
	return result;
}

int main() {
	// Directory to search, must escape \ with a \ to turn it into a character rather than an escape symbol
	std::string root = "C:\\Program Files (x86)";
	// Create a stack to keep track of the directories that we have to search
	std::vector<std::experimental::filesystem::path> dirsToDo;
	// Push back the root directory onto the stack 
	dirsToDo.push_back(root);

	// Create a container to hold the files we find
	std::vector<std::string> files;

	while (!dirsToDo.empty()) {
		std::vector<std::future<Result>> futures;
		
		// While we have less than 16 tasks and our directory stack isn't empty, make more tasks
		for (int i = 0; i < 16 && !dirsToDo.empty(); ++i) {
			auto fut = std::async(&listDir, std::move(dirsToDo.back()));
			dirsToDo.pop_back();
			futures.push_back(std::move(fut)); 
		}
		
		// While we're still expecting tasks to finish, keep requesting promises
		try {
			while (!futures.empty()) {
				auto ftr = std::move(futures.back());
				futures.pop_back();
				Result result = ftr.get();
				// Copy the result from the promise through the future
				std::copy(result.files.begin(), result.files.end(), std::back_inserter(files));
				std::copy(result.dirs.begin(), result.dirs.end(), std::back_inserter(dirsToDo));
			}
		}
		catch (std::system_error& e) {
			std::cout << "System error: " << e.code().message() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (...) {
			std::cout << "Unknown exception...\n";
		}
	}

	// Print out the files in our directory
	for (auto& item : files) {
		std::cout << item << std::endl;
	}

	std::cout << "Press enter\n";
	char c;
	std::cin.get(c);
	return 0;
}