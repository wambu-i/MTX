#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <vector>

#define FILE_OBJ std::tuple<std::string, int>

class Globals {
	public:
		Globals();
		~Globals();

		std::string user;
		std::string home;

		std::string return_day(int);

	private:
		static std::string get_user();
		static std::string get_home();

	protected:
		const std::vector<std::string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


};
#endif
