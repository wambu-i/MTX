#ifndef SORTING_H
#define SORTING_H

#include <experimental/filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <chrono>
#include <vector>
#include <ctime>
#include <tuple>
#include <string>

#include <directories.hpp>
#include <globals.hpp>
#include <logger.hpp>


namespace filesystem = std::experimental::filesystem;
namespace chrono = std::chrono;

struct file_info {
	std::string location;
	std::time_t accessed;
	std::string accessed_on;
};

class Logger;
class Directories;

class Sorting: public Globals {
	public:
		Sorting() = default;
		Sorting(std::string &s);
		Sorting(const Sorting &sort);
		Sorting &operator = (const Sorting &);
		~Sorting();

		file_info *temp;
		file_info *get_last_accessed_time(const filesystem::path);
		std::vector<file_info> *create_info();

	private:
		std::string *p;
		filesystem::path *path;
		std::vector<filesystem::directory_entry> t_dirs;
		struct stat file_data;
		std::shared_ptr<spdlog::logger> _log;
		Directories *dir;

		void sort_files(file_info);
		file_info test();
		std::string get_access_date(std::time_t);
		//file_info *compare(file_info *file_one, file_info *file_two);
		std::time_t return_time();
		std::tuple<FILE_OBJ> *construct_file_entry(std::string location);
		std::vector<filesystem::directory_entry> *walk_path();
		//void compare(std::vector<filesystem::directory_entry> *dirs);
		static bool compare(const file_info &, const file_info &);
};

#endif
