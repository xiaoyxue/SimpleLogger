#include <iostream>
#include "common/Logger.h"
#include "spdlog/fmt/fmt.h"

using namespace Gyunity;

class A {
public:
	std::string a = "abc";
	friend std::ostream& operator<<(std::ostream& os, const A &a);
};

std::ostream& operator<<(std::ostream& os, const A &a)
{
	os << a.a;
	return os;
}

int main()
{
	//Logger logger;
	//logger.SetLevel("Debug");
	//logger.Info("Info");
	//logger.Warn("Warn");
	//logger.Debug("Debug");
	//logger.Error("Error");

	GYT_SET_LOG_LEVEL("Debug");
	GYT_INFO("Info");
	GYT_INFO("Test {} {} {}", 1, 2, 3);
	GYT_WARN("Warn");
	GYT_DEBUG("Debug");
	GYT_PRINT("Test text");
	A a;
	GYT_PRINT("A a: {}", a);
	
	//GYT_ERROR("Error");
	
	return 0;
}