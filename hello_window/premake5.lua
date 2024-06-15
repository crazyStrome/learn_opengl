project "hello_window"  
    kind "ConsoleApp"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir)
	objdir ("%{wks.location}/bin-int/" .. outputdir)

    includedirs {
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
    }
    files { 
        "src/*.cc", 
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