workspace "PhysicToolkit"
    architecture "x86_64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    targetdir "bin/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}"
    objdir "bin-int/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}"

project "MarsMap"
    kind "ConsoleApp"
    language "C"
    location "src"

    includedirs {
        "src",
        "include"
    }

    files {
        "src/**.c",
        "src/**.h"
    }

    filter "system:linux"
        links {
            "GL",
            "GLEW",
            "glfw",
            "m"
        }
    filter "system:windows"
        links {
            "opengl32",
            "glew32",
            "glfw3",
            "m"
        }
