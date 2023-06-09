workspace "HoneyPie"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HoneyPie/vendor/GLFW/include"
IncludeDir["Glad"] = "HoneyPie/vendor/Glad/include"
IncludeDir["imgui"] = "HoneyPie/vendor/imgui"

include "HoneyPie/vendor/GLFW"
include "HoneyPie/vendor/GLAD"
include "HoneyPie/vendor/imgui"

project "HoneyPie"
	location "HoneyPie"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "HP_pch.h"
	pchsource "HoneyPie/src/HP_pch.cpp"
	

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
	}

	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HP_PLATFORM_WINDOWS",
			"HP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HP_DIST"
		runtime "Release"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HoneyPie/vendor/spdlog/include",
		"HoneyPie/src"
	}

	links
	{
		"HoneyPie"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HP_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HP_DIST"
		runtime "Release"
		symbols "On"