#include <sorting.hpp>
#include <directories.hpp>
#include <iostream>
#include <algorithm>

Sorting::Sorting(std::string &s): p(new std::string(s)) {
	Logger *l = new Logger("sorting");
	_log = l->return_logger();
}

Sorting::Sorting(const Sorting &sort): path(new filesystem::path(*sort.p)) {}

Sorting::~Sorting(){
	delete p;
	delete temp;
	delete path;
}

file_info *Sorting::get_last_accessed_time(const filesystem::path f) {
	_log->info("Getting file info...");

	file_info *file = new file_info;
	std::string name = filesystem::canonical(f);
	stat(name.c_str(), &file_data);

	file->location = name;
	file->accessed = file_data.st_atime;
	file->accessed_on = get_access_date(file_data.st_atime);
	return file;
}

std::string Sorting::get_access_date(std::time_t epoch) {
	std::tm *local_time = localtime(&epoch);
	std::string wday = return_day(local_time->tm_wday);
	return wday;
}

/*
void Sorting::compare(std::vector<filesystem::directory_entry> *dirs) {
    for (auto &d: *dirs) {
	file_info *temp = get_last_accessed_time(d);
    }
} */

std::vector<filesystem::directory_entry> *Sorting::walk_path() {
	_log->info("Walking path...");
	std::cout << path->string() << std::endl;
	if (path->string().empty()) {
		_log->info("No specified path. Using default home directory...");
		dir = new Directories();
	}
	else {
		_log->info("Walking directory tree from specified path...");
		dir = new Directories(path);
	}
	return dir->dirs;
}

std::vector<file_info> *Sorting::create_info() {
	_log->info("Beginning sorting process...");
	auto dirs = walk_path();

	std::vector<file_info> *files;
	for (auto &d: *dirs) {
		file_info *temp = get_last_accessed_time(d.path());
		files->push_back(*temp);
		std::sort(files->begin(), files->end(), Sorting::compare);
	}
	return files;
}

std::time_t Sorting::return_time() {
	chrono::system_clock::time_point now = chrono::system_clock::now();
	std::time_t epoch = chrono::system_clock::to_time_t(now);
	return epoch;
}


bool Sorting::compare(const file_info &a, const file_info &b) {
	return a.accessed > b.accessed;
}