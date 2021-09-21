workspace "Heat"
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
IncludeDir["GLFW"] = "Heat/vendor/GLFW/include"

include "Heat/vendor/GLFW"

project "Heat"
	location "Heat"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "htpch.h"
	pchsource "Heat/src/htpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"HT_PLATFORM_WINDOWS",
			"HT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "HT_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "HT_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Heat/vendor/spdlog/include",
		"Heat/src"
	}

	links
	{
		"Heat"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"HT_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "HT_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "HT_DIST"
			optimize "On"