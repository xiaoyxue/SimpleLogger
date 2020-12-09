#include <iostream>
#include <cassert>
#include "common/Logger.h"

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
	Print("Test text");
	A a;
	Print("A a: {}\n", a);
	int val = 1;
	GYT_ASSERT(val == 2);
	return 0;
}