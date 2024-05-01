project "GLAD"
    kind "StaticLib"
    language "C"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
    {
        "src/glad.c"
    }

    includedirs
    {
        "include/"
    }
    
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"