workspace "learn_opengl"  
    configurations { "Debug", "Release" } 

outputdir = "output"

IncludeDirs = {}
IncludeDirs["glfw"] = "%{wks.location}/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/vendor/glad/include"


include "vendor/glfw"
include "vendor/glad"

include "hello_window"