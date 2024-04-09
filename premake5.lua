workspace "Velkro"
	architecture "x64"

	configurations
	{
		"Distribution",
		"Release",
		"Debug",		
	}

outputdir = "%{cfg.buildcfg}"

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
	}

	links
	{
		"Velkro",
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

		links
		{
			"X11"
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