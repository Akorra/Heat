#pragma once

//Basic Macros

#ifdef HT_PLATFORM_WINDOWS
	#ifdef HT_BUILD_DLL
		#define HEAT_API __declspec(dllexport)
	#else
		#define HEAT_API __declspec(dllimport)
	#endif
#else
	#error Heat only supports Windows!
#endif