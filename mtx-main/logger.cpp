#include <iostream>
#include <logger.hpp>

#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

Logger::Logger(std::string s): _type(s) {}

Logger::~Logger() {
	spdlog::drop_all();
}

std::shared_ptr<spdlog::logger> Logger::create_logger() {
	std::shared_ptr<spdlog::logger> logger;
	try {
		logger = spdlog::get(_type);
		if (not logger) {
			#ifdef DEBUG
				auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
				sink->set_level(spdlog::level::debug);
				logger = std::make_shared<spdlog::logger>(_type, sink);
			#else
				auto sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("mtx.log", MAX_SIZE, MAX_FILES);
				sink->set_level(spdlog::level::info);
				logger = std::make_shared<spdlog::logger>(_type, sink);
			#endif
			spdlog::register_logger(logger);
			logger->info("Created logger for {}", _type);
			return logger;
		}
	}
	catch(const spdlog::spdlog_ex &ex) {
		std::cerr << ex.what() << '\n';
		logger = nullptr;
	}

	return logger;
}

std::shared_ptr<spdlog::logger> Logger::return_logger() {
	_logger = create_logger();
	return _logger;
}