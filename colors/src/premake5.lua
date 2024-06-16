project "colors_src"
    filename "%{prj.group}_%{prj.name}"
    kind "ConsoleApp"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.camera}",
        "%{IncludeDirs.shader}",
        "%{IncludeDirs.stb_image}",
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