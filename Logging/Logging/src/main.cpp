#include <iostream>
#include "common/Logger.h"

using namespace Gyunity;

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
	GYT_ERROR("Error");
	return 0;
}