#include <sorting.hpp>
#include <directories.hpp>
#include <iostream>
#include <algorithm>

//#define LOG() std::cout << __PRETTY_FUNCTION__ << std::endl

Sorting::Sorting(std::string &s): p(new std::string(s)) {
	Logger *l = new Logger("sorting");
	auto _log = l->return_logger();
}

Sorting::Sorting(const Sorting &sort): path(new filesystem::path(*sort.p)) {
/*     auto l = new Logger("sorting");
    _log = l->return_logger("sorting");
    auto _log = l->return_logger("sorting"); */
/*     auto _log = l->return_logger("sorting"); */
/*    auto _log = nullptr;
    if (_log)
	_log->warn("Creating a filesystem path");
    else{
	std::cout << "Creating a filesystem path" << std::endl;
	std::cout << path << std::endl;
    }
    //ss_log->info("Hello from here!"); */
    std::cout << "Creating a filesystem path" << std::endl;
    std::cout << path << std::endl;
}

Sorting::~Sorting(){
    delete p;
    delete temp;
    delete path;
}

file_info *Sorting::get_last_accessed_time(Sorting s) {
    file_info *file = new file_info;
    std::string name = filesystem::canonical(*s.path);
    std::cout << name << std::endl;
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

std::vector<file_info> *Sorting::create_info(std::vector<filesystem::directory_entry> *dirs) {
    std::vector<std::tuple<std::string, int>> tmp;
    std::vector<file_info> *files;
    for (auto &d: *dirs) {
       /*  file_info *temp = get_last_accessed_time(d);
	files->push_back(*temp);
	std::sort(files->begin(), files->end(), Sorting::compare); */
	;
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

//std::shared_ptr<logger::logger> Sorting::create_log(std::string name) {
//    auto *inst = new Logger(name);
//    auto log = inst->return_logger(name);
//    return log;
//}