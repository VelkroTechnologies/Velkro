-- Premake Project Structure
workspace "Velkro"
    configurations { "Development", "Distribution" }
    language "C++"
    cppdialect "C++latest"

startproject "Simulation"

include "vendor/glfw/GLFW.lua"

project "Velkro"
    kind "StaticLib"
    location "%{prj.name}"
    targetdir "bin/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    architecture "x64"    

    links { "GLFW" }
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs { "vendor/glfw/include" }

    filter "configurations:Development"
        defines { "VLK_DEVELOPMENT" }
        symbols "On"

    filter "configurations:Distribution"
        optimize "On"

project "Project"
    kind "ConsoleApp"
    location "%{prj.name}"
    targetdir "bin/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.architecture}-%{cfg.buildcfg}"
    architecture "x64"

    links { "Velkro" }
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    
    includedirs { "Velkro/src", "vendor/glfw/include" }

    filter "configurations:Development"
        symbols "On"

    filter "configurations:Distribution"
        optimize "On"