project "prac1"  
    kind "ConsoleApp"   
    language "C++"   
    targetdir "%{wks.location}/bin/%{prj.group}/%{prj.name}" 
    objdir "%{wks.location}/obj/%{prj.group}/%{prj.name}" 

    includedirs {
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
    }
    files { 
        "*.cc", 
    }
    links {
        "glfw",
        "GL",
        "glad",
    }
    targetname "%{prj.group}"
    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 