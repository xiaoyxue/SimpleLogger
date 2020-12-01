#pragma once

#include "Core.h"
#include "spdlog/common.h"
#include "spdlog/fmt/fmt.h"

namespace spdlog {
	class logger;
}

GYT_NAMESPACE_BEGIN

class Logger {
private:
	std::string mLevelName;
	std::shared_ptr<spdlog::logger> mpConsole;
public:
	Logger();
	void Info(const std::string& msg) const;
	void Warn(const std::string& msg) const;
	void Debug(const std::string& msg) const;
	void Error(const std::string& msg, bool raiseException = true) const;
	void Critical(const std::string& msg, bool raiseException = true) const;
	void Flush() const;
	void SetLevel(const std::string &levelName = "Info");
	static int LevelFromString(const std::string& levelName);
};

Logger& GetLogger();

GYT_NAMESPACE_END