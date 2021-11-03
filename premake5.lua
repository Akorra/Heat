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
IncludeDir["glm"] = "Heat/vendor/glm"

group "Dependencies"
	include "Heat/vendor/GLFW"
	include "Heat/vendor/Glad"
	include "Heat/vendor/imgui"
group ""

project "Heat"
	location "Heat"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "htpch.h"
	pchsource "Heat/src/htpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"HT_PLATFORM_WINDOWS",
			"HT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		--}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "HT_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "HT_DIST"
			runtime "Release"
			optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Heat/src",
		"Heat/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Heat"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HT_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "HT_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "HT_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "HT_DIST"
			runtime "Release"
			optimize "on"