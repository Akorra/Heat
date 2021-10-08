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
IncludeDir["Glad"] = "Heat/vendor/Glad/include"
IncludeDir["ImGui"] = "Heat/vendor/imgui"

group "Dependencies"
	include "Heat/vendor/GLFW"
	include "Heat/vendor/Glad"
	include "Heat/vendor/imgui"
group ""

project "Heat"
	location "Heat"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"HT_PLATFORM_WINDOWS",
			"HT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "HT_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "HT_DIST"
			runtime "Release"
			optimize "On"

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
		"Heat/vendor/spdlog/include",
		"Heat/src"
	}

	links
	{
		"Heat"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"HT_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "HT_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "HT_DIST"
			runtime "Release"
			optimize "On"