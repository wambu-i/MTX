#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sorting.hpp>
#include <logger.hpp>
#include <experimental/filesystem>

namespace filesystem = std::experimental::filesystem;

int main() {
	std::string p = "/home/wambui/";
	Sorting *sort = new Sorting(p);
	Sorting *test(sort);
	auto *t = test->create_info();

	return 0;
}
