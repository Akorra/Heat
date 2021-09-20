#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Heat {
	class HEAT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log macros
#define HT_CORE_TRACE(...) ::Heat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HT_CORE_INFO(...)  ::Heat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HT_CORE_WARN(...)  ::Heat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HT_CORE_ERROR(...) ::Heat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HT_CORE_FATAL(...) ::Heat::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define HT_TRACE(...) ::Heat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HT_INFO(...)  ::Heat::Log::GetClientLogger()->info(__VA_ARGS__)
#define HT_WARN(...)  ::Heat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HT_ERROR(...) ::Heat::Log::GetClientLogger()->error(__VA_ARGS__)
#define HT_FATAL(...) ::Heat::Log::GetClientLogger()->fatal(__VA_ARGS__)
