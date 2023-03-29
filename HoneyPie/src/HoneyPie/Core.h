#pragma once

#ifdef HP_PLATFORM_WINDOWS
	#ifdef HP_BUILD_DLL
		#define HONEYPIE_API __declspec(dllexport)
	#else
		#define HONEYPIE_API __declspec(dllimport)

	#endif // HP_BUILD_DLL
#else
	#error Honeypie only supports Windows!
#endif // HP_PLATFORM_WINDOWS
