#ifndef DIRECTORIES
#define DIRECTORIES

#include <string>
#include <vector>
#include <experimental/filesystem>
#include <globals.hpp>

namespace filesystem = std::experimental::filesystem;

class Directories: public Globals {
	public:
		Directories();
		~Directories();
		filesystem::path to_follow;
		std::vector<filesystem::directory_entry> *dirs;
		std::vector<filesystem::directory_entry> *files;

	private:
		filesystem::path *base;
		Globals *params;

		filesystem::path return_absolute_path(filesystem::path);
		filesystem::directory_iterator return_directory_iterator(filesystem::path);
		void sorted_entries(filesystem::path);
		bool isHiddenFile(const filesystem::path &);
};

#endif

