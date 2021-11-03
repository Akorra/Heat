#pragma once

//Basic Macros

#ifdef HT_PLATFORM_WINDOWS
	#if HT_DYNAMIC_LINK
		#ifdef HT_BUILD_DLL
			#define HEAT_API __declspec(dllexport)
		#else
			#define HEAT_API __declspec(dllimport)
		#endif
	#else
		#define HEAT_API
	#endif
#else
	#error Heat only supports Windows!
#endif

#ifdef HT_ENABLE_ASSERTS
	#define HT_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
	#define HT_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
#else
	#define HT_ASSERT(x, ...)
	#define HT_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define HT_BIND_EVENT_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)