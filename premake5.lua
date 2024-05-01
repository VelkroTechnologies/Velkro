workspace "Velkro"
	architecture "x64"

	configurations
	{
		"Distribution",
		"Release",
		"Debug",		
	}

outputdir = "%{cfg.buildcfg}"

include "Velkro/vendor/glfw"
include "Velkro/vendor/glad"
include "Velkro/vendor/imgui"

project "Velkro"
	location "Velkro"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-int/%{prj.name}/" .. outputdir)

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"Velkro/vendor/glfw/include",
		"Velkro/vendor/glad/include",
		"Velkro/vendor/glm",
		"Velkro/vendor/imgui"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
   
		defines
		{
			"VLK_PLATFORM_WINDOWS"		
		}
	
	filter "system:linux"
		defines
		{
			"VLK_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "VLK_DEBUG_CONFIG"
		symbols "On"

	filter "configurations:Release"
		defines "VLK_RELEASE_CONFIG"
		optimize "On"

	filter "configurations:Distribution"
		defines "VLK_DISTRIBUTION_CONFIG"
		optimize "On"

project "Runtime"
	location "Runtime"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-int/%{prj.name}/" .. outputdir)

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"Velkro/src",
		"Velkro/vendor/glfw/include",
		"Velkro/vendor/glad/include",
		"Velkro/vendor/glm",
		"Velkro/vendor/imgui"
	}

	links
	{
		"Velkro",
		"ImGUI",
		"GLFW",
		"GLAD",		
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VLK_PLATFORM_WINDOWS"
		}

		links
		{
			"opengl32"
		}
	
	filter "system:linux"
		defines
		{
			"VLK_PLATFORM_LINUX"
		}		

	filter "configurations:Debug"
		defines "VLK_DEBUG_CONFIG"
		symbols "On"

	filter "configurations:Release"
		defines "VLK_RELEASE_CONFIG"
		optimize "On"

	filter "configurations:Distribution"
		defines "VLK_DISTRIBUTION_CONFIG"
		optimize "On"