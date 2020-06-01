#ifndef LOGGER
#define LOGGER

#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"

#define MAX_SIZE 1024 * 1024 * 5
#define MAX_FILES 5

class Logger {
	public:
		Logger(std::string);
		~Logger();

		std::shared_ptr<spdlog::logger> return_logger();
	private:
		std::string _type;
		std::shared_ptr<spdlog::logger> _logger;


		std::shared_ptr<spdlog::logger> create_logger();
};
#endif