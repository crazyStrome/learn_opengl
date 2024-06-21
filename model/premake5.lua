project "model"  
    kind "StaticLib"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "%{IncludeDirs.shader}",
        "%{IncludeDirs.mesh}",
        "%{IncludeDirs.model}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.stb_image}",
    }
    files { 
        "src/*.cc", 
    }
    links {
        "glad",
        "shader",
        "mesh",
    }
    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 