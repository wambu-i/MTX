#include <directories.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>

Directories::Directories(filesystem::path *p): base(p) {
	to_follow = return_absolute_path(*base);
	sorted_entries(to_follow);
}

Directories::Directories() {
	params = new Globals;
	to_follow = return_absolute_path(params->home);
	sorted_entries(to_follow);
}


Directories::~Directories() {
	delete params;
        delete base;
}

filesystem::path Directories::return_absolute_path(filesystem::path r_path) {
	return filesystem::canonical(r_path);
}

filesystem::directory_iterator Directories::return_directory_iterator(filesystem::path a_path) {
	return filesystem::directory_iterator(a_path);
}

void Directories::sorted_entries(filesystem::path f_path) {
	for (auto &entry: filesystem::directory_iterator(f_path)) {
		if (!isHiddenFile(entry.path())) {
			if (filesystem::is_directory(entry)) {
				dirs->push_back(entry);
			}
			else if (filesystem::is_regular_file(entry)) {
				files->push_back(entry);
			}
		}
	} 
}

bool Directories::isHiddenFile(const filesystem::path &to_check) {
	auto name = (std::string) to_check.filename();
	if (name[0] == '.') {
		return true;
	}
	return false;
}
