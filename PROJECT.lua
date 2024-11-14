-- Premake Project Structure
workspace "Velkro"
    configurations { "Development", "Distribution" }
    language "C++"
    cppdialect "C++latest"
    startproject "Simulation"
    
project "Velkro"
    kind "StaticLib"    
    targetdir "bin/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    location "%{prj.name}"
    architecture "x64"

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    filter "configurations:Development"
        defines { "VLK_DEVELOPMENT" }
        symbols "On"

    filter "configurations:Distribution"
        optimize "On"

project "Project"
    kind "ConsoleApp"
    targetdir "bin/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    location "%{prj.name}"
    architecture "x64"

    links { "Velkro" }
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    
    includedirs { "Velkro/src" }

    filter "configurations:Development"
        symbols "On"

    filter "configurations:Distribution"
        optimize "On"