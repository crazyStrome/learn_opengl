project "shaders_src"  
    filename "%{prj.group}_%{prj.name}"
    kind "ConsoleApp"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir)
	objdir ("%{wks.location}/bin-int/" .. outputdir)

    includedirs {
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
    }
    files { 
        "main.cc", 
    }
    links {
        "glfw",
        "GL",
        "glad",
    }
    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 