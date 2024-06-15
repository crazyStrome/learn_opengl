project "shaders_prac1"  
    filename "%{prj.group}_%{prj.name}"
    kind "ConsoleApp"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.shader}",
    }
    files { 
        "main.cc", 
    }
    links {
        "glfw",
        "GL",
        "glad",
        "shader",
    }
    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 