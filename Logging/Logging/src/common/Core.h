#pragma once
#include "Def.h"
#include "spdlog/fmt/bundled/ostream.h"
#include <vector>

GYT_NAMESPACE_BEGIN

#define GYT_UNREACHABLE __assume(0);

#define Print(...) fmt::print(__VA_ARGS__)

#define SPD_LOG(X, ...) Gyunity::GetDefaultLogger()->X(fmt::format(__VA_ARGS__))

#define SPD_INFO_LOG(X, ...) Gyunity::GetInfoLogger()->X(fmt::format(__VA_ARGS__))

#define SPD_LOCATED_LOG(X, ...)                                                 \
  Gyunity::GetDefaultLogger()->X(                                               \
      fmt::format("[{}: {} @{}] ", __FILE__, __FUNCTION__, __LINE__) +          \
      fmt::format(__VA_ARGS__))

#define GYT_PRINT(...) SPD_INFO_LOG(Info, __VA_ARGS__)
#define GYT_SET_LOG_LEVEL(Level) Gyunity::GetDefaultLogger()->SetLevel(Level)
#define GYT_INFO(...) SPD_LOG(Info, __VA_ARGS__)
#define GYT_WARN(...) SPD_LOCATED_LOG(Warn, __VA_ARGS__)
#define GYT_DEBUG(...) SPD_LOCATED_LOG(Debug, __VA_ARGS__)
#define GYT_TRACE(...) SPD_LOCATED_LOG(Trace, __VA_ARGS__)
#define GYT_ERROR(...)                          \
do                                              \
{                                               \
    SPD_LOCATED_LOG(Error, __VA_ARGS__);        \
    exit(2);                                    \
    GYT_UNREACHABLE                             \
} while (0)


#define GYT_STATIC_ASSERT(x) static_assert((x), #x)
#define GYT_STATIC_ASSERT_INFO(x, info) static_assert((x), info)

#define GYT_ASSERT(x) GYT_ASSERT_INFO((x), "Assertion failure: " #x)

#define GYT_ASSERT_INFO(x, ...)             \
do                                          \
{                                           \
    if (!(x))                               \
    {                                       \
        GYT_ERROR(__VA_ARGS__);             \
    }                                       \
} while(0)

GYT_NAMESPACE_END