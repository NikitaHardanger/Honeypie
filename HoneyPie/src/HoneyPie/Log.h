#pragma once


#include "Core.h"
#include <spdlog/spdlog.h>
#include "spdlog/fmt/ostr.h"

namespace Honeypie {

	class HONEYPIE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()		{ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()	{ return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HP_CORE_TRACE(...)		::Honeypie::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HP_CORE_INFO(...)		::Honeypie::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HP_CORE_WARN(...)		::Honeypie::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HP_CORE_ERROR(...)		::Honeypie::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HP_CORE_FATAL(...)		::Honeypie::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HP_TRACE(...)			::Honeypie::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HP_INFO(...)			::Honeypie::Log::GetClientLogger()->info(__VA_ARGS__)
#define HP_WARN(...)			::Honeypie::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HP_ERROR(...)			::Honeypie::Log::GetClientLogger()->error(__VA_ARGS__)
#define HP_FATAL(...)			::Honeypie::Log::GetClientLogger()->fatal(__VA_ARGS__)