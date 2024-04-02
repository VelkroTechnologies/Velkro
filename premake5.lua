workspace "Velkro"
	architecture "x64"

	configurations
	{
		"Distribution", -- The default configuration
		"Release",
		"Debug",		
	}

outputdir = "%{cfg.buildcfg}"

project "Velkro"
	location "Velkro"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-int/%{prj.name}/" .. outputdir)

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
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
		defines "VLK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VLK_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "VLK_DISTRIBUTION"
		optimize "On"

project "Runtime"
	location "Runtime"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-int/%{prj.name}/" .. outputdir)

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Velkro/src",
	}

	links
	{
		"Velkro"
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
		defines "VLK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VLK_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "VLK_DISTRIBUTION"
		optimize "On"