#ifdef _WIN32
	#define CONFIG "%PROGRAMDATA%\MTX\config"
	#define HOME "C:/Users/"
	#define USER "USERNAME"
#elif __linux__
	#define USER "USER"
	#define HOME "/home/"
#endif
#include <string>
#include "globals.hpp"

Globals::Globals() {
	user = get_user();
	home = get_home();
}

Globals::~Globals() {}
	std::string Globals::get_user() {
	std::string t_user = getenv(USER);
	return t_user;
}

std::string Globals::get_home() {
	std::string t_home = std::string(HOME) + get_user();
	return t_home;
}

std::string Globals::return_day(int i) {
	return weekdays[i];
}