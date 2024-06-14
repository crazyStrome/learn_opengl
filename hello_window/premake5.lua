project "hello_window"  
    kind "ConsoleApp"   
    language "C++"   
    targetdir "../bin/%{prj.name}" 
    objdir "../obj/%{prj.name}" 

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