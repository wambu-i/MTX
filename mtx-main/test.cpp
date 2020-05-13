#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sorting.hpp>
#include <logger.hpp>
#include <experimental/filesystem>

namespace filesystem = std::experimental::filesystem;

int main() {
	//  std::string x = "mtx.json";
	//Config *file = new Config(x);
	//file->configFile.open(x);
	//std::cout << file << std::endl;
	//  Directories *dir = new Directories;
	//std::cout << dir->to_follow << std::endl;
	//for (auto &d : dir->dirs) {
	//std::cout << d << std::endl;
	//}
	//filesystem::path x = '/home/wambui/Programming';
	//Sorting *sort = new Sorting;
	//logger::init_thread_pool(32768, 1);
	std::string p = "/home/wambui/MTX/mtx-main";
	Sorting *sort = new Sorting(p);
	//filesystem::path entry = "/home/wambui/MTX/mtx-main";
	sort->temp = sort->get_last_accessed_time(*sort);

	Logger *l = new Logger("test");
	std::cout << "File name: " << sort->temp->location << std::endl;
	//std::cout << "Accessed: " << sort->temp->date << std::endl;
	std::cout << "Accessed on: " << sort->temp->accessed << std::endl;
	auto logger = l->return_logger();
	logger->info("Hello, this is a test");

	return 0;
}
