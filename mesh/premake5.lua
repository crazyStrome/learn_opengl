project "mesh"  
    kind "StaticLib"   
    language "C++"   
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.shader}",
        "%{IncludeDirs.mesh}",
        "%{IncludeDirs.assimp}",
    }
    files { 
        "src/*.cc", 
    }
    links {
        "glad",
        "shader",
    }
    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 