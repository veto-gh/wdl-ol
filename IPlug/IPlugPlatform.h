#pragma once

/**
 * @file
 * @brief Include to get consistently named preprocessor macros for different platforms and logging functionality
 */

#ifdef _WIN32
  #define OS_WIN
#elif defined __APPLE__
  #include <TargetConditionals.h>
  #if TARGET_OS_MAC
    #define OS_MAC
  #endif
#elif defined __linux || defined __linux__ || defined linux
  #define OS_LINUX
#elif defined EMSCRIPTEN
  #define OS_WEB
#else
  #error "No OS defined!"
#endif

#if defined(_WIN64) || defined(__LP64__)
  #define ARCH_64BIT
#endif

#include <cstring>
#include <cstdlib>

#include "IPlugLogger.h"

#ifdef NO_PARAMS_MUTEX
#define ENTER_PARAMS_MUTEX
#define LEAVE_PARAMS_MUTEX
#define ENTER_PARAMS_MUTEX_STATIC
#define LEAVE_PARAMS_MUTEX_STATIC
#else
#define ENTER_PARAMS_MUTEX mParams_mutex.Enter(); Trace(TRACELOC, "%s", "ENTER_PARAMS_MUTEX")
#define LEAVE_PARAMS_MUTEX mParams_mutex.Leave(); Trace(TRACELOC, "%s", "LEAVE_PARAMS_MUTEX")
#define ENTER_PARAMS_MUTEX_STATIC _this->mParams_mutex.Enter(); Trace(TRACELOC, "%s", "ENTER_PARAMS_MUTEX")
#define LEAVE_PARAMS_MUTEX_STATIC _this->mParams_mutex.Leave(); Trace(TRACELOC, "%s", "LEAVE_PARAMS_MUTEX")
#endif
